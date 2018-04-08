#include<stdio.h>
int main()
{
	int i,j;
	int alloc[3][3] = {{0,0,1},{3,2,0},{2,1,1}};
	int max[3][3] = {{8,4,3},{6,2,0,},{3,3,3}};
	int avail[3]={3,2,2};
	int work[3]={3,2,2};
	int finish[3]={0,0,0};
	printf("******THE GIVEN ALLOCATION MATRIX IS****** \n");
	printf("A B C\n");
	for( i=0;i<3;i++)
	{	
		for( j = 0;j<3;j++)
		{
			printf("%d ",alloc[i][j]);	
		}
		printf("\n");
	}
		printf("******THE GIVEN MAX MATRIX IS****** \n");
	printf("A B C\n");
	for( i=0;i<3;i++)
	{	
		for( j = 0;j<3;j++)
		{
			printf("%d ",max[i][j]);	
		}
		printf("\n");
	}
	
	int need[3][3];
	for(i = 0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\n ******THE NEED IS******\n");
	printf(" A B C\n");
	for( i=0;i<3;i++)
	{	
		for( j = 0;j<3;j++)
		{
			printf(" %d",need[i][j]);	
		}
		printf("\n");
	}
	printf("\n******THE AVAILABLE IS******\n ");
	for(i=0;i<3;i++)
	{
		printf("%d ",work[i]);
	}
	printf("\n*** SAFE SEQUENCE TO AVOID DEADLOCK IS ***\n");
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			if(finish[i]==0 && need[i][0]<=work[0] && need[i][1]<=work[1] && need[i][2]<=work[2])
			{
				printf("P%d==>>",i);
				work[0]=work[0]+alloc[i][0];
				work[1]=work[1]+alloc[i][1];
				work[2]=work[2]+alloc[i][2];
				finish[i]=1;	
			}
			
		}
	}
	printf("\n\n\n\n THE TOTAL INSTANCE OF A B C is : ");
    for(i = 0;i<3;i++)
	{
			printf("%d  ",work[i]);
	}	
	
	int req[3]={0,0,2};//P0 requests for the resources
	printf("\n\n****NOW THE PO MAKES REQUEST OF 0 0 2 ********\n");
	
	if(req[0]<=need[0][0] && req[1]<=need[0][1] && req[2]<=need[0][2] && req[0]<=avail[0] && req[1]<=avail[1] && req[2]<=avail[2])
	{
		avail[0] -= req[0];
		avail[1] -= req[1];
		avail[2] -= req[2];
		
		alloc[0][0] += req[0];
		alloc[0][1] += req[1];
		alloc[0][2] += req[2];
		
		need[0][0] -= req[0];
		need[0][1] -= req[1];
		need[0][2] -= req[2];
	}
	
		printf("\n******THE ALLOCATION MATRIX after request  IS****** \n");
	printf("A B C\n");
	for( i=0;i<3;i++)
	{	
		for( j = 0;j<3;j++)
		{
			printf("%d ",alloc[i][j]);	
		}
		printf("\n");
	}
	
			printf("******THE need MATRIX after request is  IS****** \n");
	printf("A B C\n");
	for( i=0;i<3;i++)
	{	
		for( j = 0;j<3;j++)
		{
			printf("%d ",need[i][j]);	
		}
		printf("\n");
	}
	
		printf("\n******THE AVAILABLE after request IS******\n ");
	for(i=0;i<3;i++)
	{
		printf("%d ",avail[i]);
	}
	finish[0]=0; finish[1]=0;finish[2]=0;
	
	printf("\n*** SAFE SEQUENCE TO AVOID DEADLOCK IS ***\n");
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			if(finish[i]==0 && need[i][0]<=work[0] && need[i][1]<=avail[1] && need[i][2]<=avail[2])
			{
				printf("P%d==>>",i);
				avail[0]=avail[0]+alloc[i][0];
				avail[1]=avail[1]+alloc[i][1];
				avail[2]=avail[2]+alloc[i][2];
				finish[i]=1;	
			}
			
		}
	}

	
	
	
}

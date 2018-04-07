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
	for( i=0;i<3;i++)
	{	
		for( j = 0;j<3;j++)
		{
			printf("%d ",alloc[i][j]);	
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
    for(i = 0;i<3;i++)
	{
			printf("\n  %d",work[i]);
	}	
}

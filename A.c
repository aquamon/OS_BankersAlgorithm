#include<stdio.h>
int main()
{
	int res,pro,i,j,p_no;
	printf("\nenter thr no. of processes :");
	scanf("%d",&pro);
	printf("\nenter the no. of resources :");
	scanf("%d",&res);
	int alloc[pro][res],max[pro][res],avail[res],need[pro][res],requ[res];
	printf("\nenter the allocated resource instance to processes\n");
	for(i=0;i<pro;i++)
	{
		printf("\nenter the allocation for P%d resource :",i);
		for(j=0;j<res;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<pro;i++)
	{
		printf("\nenter the max instance to processes P%d\n",i);
		for(j=0;j<res;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	//  enter available
	printf("\nenter the available resource :");
	for(i=0;i<res;i++)
	{
		scanf("%d",&avail[i]);
	}
	//calculate need
	for(i=0;i<pro;i++)
	{
		for(j=0;j<res;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	//display max and allocation
	printf("\nTHE ALLOCATION MATRIX\t THE MAX MATRIX \n");
	for(i=0;i<pro;i++)
	{
		for(j=0;j<res;j++)
		{
			printf("%d  ",alloc[i][j]);
		}
		printf("\t\t\t");
		for(j=0;j<res;j++)
		{
			printf("%d  ",max[i][j]);
		}
		printf("\n");
		
	}
	//display need
	printf("\nthe need matrix is \n");
	for(i=0;i<pro;i++)
	{
		for(j=0;j<res;j++)
		{
			printf("%d  ",need[i][j]);
		}
		printf("\n");
	}
	while(1)
	{
		//enter request
		printf("\nWhich process makes the request? ## enter from 0 to %d ## : ",pro-1);
		scanf("%d",&p_no);
		printf("\nEnter the request for process P%d : ",p_no);
		for(i=0;i<res;i++)
			scanf("%d",&requ[i]);		
		
		//comparision for valid request
		int compArr[res];
		for(i=0;i<res;i++)
		{
			compArr[i]=0;
		}
		int sum = 0;
		for(i=0;i<res;i++)
		{
			if(requ[i]<=need[p_no][i] && requ[i]<=avail[i])
			{
				compArr[i]=1;
			}
		}
		for(i=0;i<res;i++)
		{
			sum = sum+compArr[i];
		}
		//printf("%d",sum);
		if(sum == res)
		{
			printf("KUDOS !! valid request ");
			for(i=0;i<res;i++)
			{
				avail[i] -= requ[i];
				need[p_no][i]  -= requ[i];
				alloc[p_no][i] += requ[i];
			
			}
			break;
			
			
		}
		else
		{
			printf("invalid request <<<<>>>>> please enter again");
			
		}
		
		
	}

	//display of new allocation and need
		printf("\nTHE ALLOCATION MATRIX\t THE NEED MATRIX \n");
	for(i=0;i<pro;i++)
	{
		for(j=0;j<res;j++)
		{
			printf("%d  ",alloc[i][j]);
		}
		printf("\t\t\t");
		for(j=0;j<res;j++)
		{
			printf("%d  ",need[i][j]);
		}
		printf("\n");
		
	}
	//display of new avail
	printf("\nthe avail list is :");
	for(i=0;i<res;i++)
	{
		printf("%d ",avail[i]);
	}
	
}

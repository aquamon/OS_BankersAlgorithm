#include<stdio.h>
int main()
{
	int res,pro,i,j,p_no;int process,count = 0;int safseq[20];
	printf("\nenter thr no. of processes :");
	scanf("%d",&pro);
	printf("\nenter the no. of resources :");
	scanf("%d",&res);
	int alloc[pro][res],max[pro][res],avail[res],need[pro][res],requ[res];
	printf("\nenter the allocated resource instance to processes\n");
	//enter allocation
	for(i=0;i<pro;i++)
	{
		printf("\nenter the allocation for P%d resource :",i);
		for(j=0;j<res;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	//enter max
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
			printf("KUDOS !! YOU HAVE ENTERED A  valid request ");
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
	//display of new available list
	printf("\nthe avail list is :");
	for(i=0;i<res;i++)
	{
		printf("%d ",avail[i]);
	}
	printf("\n");
	
	//to check occurence of deadlock.
	int finish[res];
	for(i=0;i<res;i++)
		finish[i]=0;
		
	do
	{
		process = -1;
		
		for(i = 0;i<pro;i++)
		{
			if(finish[i]==0)
			{
				process = i;
				for(j=0;j<res;j++)
				{
					if(avail[j]<need[i][j])
					{
						process = -1;
						break;
					}
				}
			}
			if(process != -1)
				break;
		}
		if(process != -1)
		{
			printf("\n process P%d executed",process);
			safseq[count] = process + 1;
			count++;
			for(i = 0;i<res;i++)
			{
				avail[i] += alloc[process][i];
				finish[process] = 1;
			}
			
		}
		
	}while(count != pro && process != -1);
	
	if(count == pro)
	{
		printf("\n the system is in safe state");
		printf("\n SAFE SEQUENCE IS : ");
		for(i=0;i<pro;i++)
		{
			printf("%d  ",safseq[i]);
		}
		
	}
	else
	{
		printf("\n UNSAFE STATE HAS OCCURRED !!");
	}
}

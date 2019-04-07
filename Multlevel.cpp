#include<stdlib.h>
#include<stdio.h>
struct process
{
	int ArrivalTime;
	int BurstTime;
	int QueueNumber;
};
int main()
{
	struct process p[5];
	printf("Enter the process arrival time blah blah blah blah....\n");
	for(int i = 0;i < 5;i++)
	{
		scanf("%d",&p[i].ArrivalTime);
		scanf("%d",&p[i].BurstTime);
		scanf("%d",&p[i].QueueNumber);
	}
	
	
	
	for(int i = 0;i < 5;i++)
	{
		printf("%d",p[i].ArrivalTime);
		printf("%d",p[i].BurstTime);
		printf("%d",p[i].QueueNumber);
	}
return 0;	
}

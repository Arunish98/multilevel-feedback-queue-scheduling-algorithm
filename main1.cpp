#include<stdio.h>
#include<vector>
#include<iterator>
struct process
{
    int Burst_Time;
    int Turnaround_Time;
    int  Waiting_Time;
    int Remaining_Time;
};

void RoundRobin_Schedular(std::vector<process> &v1,int quantum)
{
    
    for(int i = 0;i < v1.size();i++)
    {
    	
        if(v1.at(i).Remaining_Time >= quantum)
        {
            v1.at(i).Remaining_Time -= quantum;
            for(int j=0;j < v1.size();j++)
            {
                if(j!=i)
                {
                    v1.at(j).Waiting_Time += quantum;
                }
            }
        }
        else
        {
            for(int j=0;j < v1.size();j++)
            {
                if(j!=i)
                {
                    v1.at(j).Waiting_Time += v1.at(i).Remaining_Time;
                }
            }
            v1.at(i).Remaining_Time = 0;
        }
        

    } 
}

void FCFS_Schedular(std::vector<process> &v1)
{
    for(int i=0;i<v1.size();i++)
    {
        if(v1.at(i).Remaining_Time != 0)
        {
            for(int j=0;j<v1.size();j++)
            {
                if(j!=i)
                {
                	if(v1.at(j).Remaining_Time != 0)
                    v1.at(j).Waiting_Time += v1.at(i).Remaining_Time;
                }
            }   
            v1.at(i).Remaining_Time = 0;
        }
        else
        {
            continue;
        }
        
    }
}
void Calculate_Turnaround(std::vector<process> &v1)
{
    for(int i=0;i<v1.size();i++)
    {
        v1.at(i).Turnaround_Time = v1.at(i).Waiting_Time + v1.at(i).Burst_Time;
    }
}


float Calculate_Average_Waiting(std::vector<process> v1,int num)
{
    int avg=0;
    for(int i=0;i<v1.size();i++)
    {
        avg += v1.at(i).Waiting_Time;
    }
    float avgf = (float)avg/num;
    return avgf;
}


float Calculate_Average_Turnaround(std::vector<process> v1,int num)
{
    int avg=0;
    for(int i=0;i<v1.size();i++)
    {
        avg += v1.at(i).Turnaround_Time;
    }
    float avgf = (float)avg/num;
    return avgf;
}

void print(std::vector<process> v1)
{
	for(int i=0;i<v1.size();i++)
    {
        printf("%d   %d   %d  %d\n",v1.at(i).Burst_Time,v1.at(i).Remaining_Time,v1.at(i).Waiting_Time,v1.at(i).Turnaround_Time);
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Enter the number of process \n");
    scanf(" %d",&num);
    struct process p[1000];
    for(int i=0;i<num;i++)
    {
        printf("\n Enter the burst time of process[%d] ",i+1);
        scanf("%d",&p[i].Burst_Time);
        p[i].Remaining_Time = p[i].Burst_Time;
        p[i].Waiting_Time = 0;
    }
    std::vector<process> v;

    for(int i = 0;i < num;i++)
    {
        v.push_back(p[i]);
    }
    //print(v);
        RoundRobin_Schedular(v,8);
        //print(v);
        RoundRobin_Schedular(v,16);
        //print(v);
        FCFS_Schedular(v);
        //print(v);
        

    

    Calculate_Turnaround(v);
    

     float Average_Turnaround = Calculate_Average_Turnaround(v,num);
    float Average_Waiting = Calculate_Average_Waiting(v,num);
    printf("average Turnaround Time =%f ",Average_Turnaround);
    printf("average Waiting Time =%f ",Average_Waiting);
}
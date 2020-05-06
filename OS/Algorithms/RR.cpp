#include<bits/stdc++.h>
using namespace std;
int main()
{
	
int Arrival_time[100];
int burst_time[100];
int ct[100],Turn_around_time[100],Waiting_time[100];
int n;
int remaining_time[100];
int total_turnaround_time=0,total_waiting_time=0;
cout<<"Enter the number of process";	
cin>>n;
cout<<"\nEnter the arrival time and burst time: ";
for(int i=0;i<n;i++)
{
 cin>>Arrival_time[i];
 cin>>burst_time[i];
}	
int time_quantum;
cout<<"Enter the quantum time: ";
cin>>time_quantum;

 for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(Arrival_time[i]>Arrival_time[j])
			{
				int temp=Arrival_time[j];
				Arrival_time[j]=Arrival_time[i];
				Arrival_time[i]=temp;
				temp=burst_time[j];
				burst_time[j]=burst_time[i];
				burst_time[i]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
	remaining_time[i]=burst_time[i];
       }
int time=0;
int i=0,flag=0;
int count=0;
while(count!=n)
{
	if(remaining_time[i]<=time_quantum && remaining_time[i]>0)
	{
       time+=remaining_time[i];
	   remaining_time[i]=0;	
	   flag=1;	
	}
	else
	if(remaining_time[i]>0)
	{
		remaining_time[i]-=time_quantum;
		time+=time_quantum;
	}
	
	if(remaining_time[i]==0 && flag==1)
	{
		count++;
		Turn_around_time[i]=time-Arrival_time[i];
		total_turnaround_time+=Turn_around_time[i];
		Waiting_time[i]=Turn_around_time[i]-burst_time[i];
		total_waiting_time+=Waiting_time[i];
        flag=0;
	}
	
	if(i==n-1)
	{
		i=0;
	}
	else
	if(Arrival_time[i+1]<=time)
	{
		i++;
	}
	else
	{
		i=0;
	}
}
cout<<"\nBurst\t    Arrival\t    Waiting\t    Turn-around\n";
for(int i=0;i<n;i++)
{
cout<<"  "<<burst_time[i]<<"\t\t"<<Arrival_time[i]<<"\t\t"<<Waiting_time[i]<<"\t\t"<<Turn_around_time[i]<<endl;
}

cout<<"\nAverage Turn_around_time time : "<<(total_turnaround_time*1.0)/n<<endl;	
cout<<"\nAverage waiting time : "<<(total_waiting_time*1.0)/n<<endl;	
}



























#include<iostream>
using namespace std;
int main()
{
			
	int at[100],bt[100],priority[100],ct[100],tat[100],wt[100];
	int n;
	cout<<"Enter the number of process";	
	cin>>n;
	cout<<"\nEnter the arrival time , burst time and its priority : ";
	for(int i=0;i<n;i++){
		cin>>at[i];
		cin>>bt[i];
		cin>>priority[i];
	}	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(at[i]>at[j]){
				swap(at[i],at[j]);
				swap(bt[i],bt[j]);
				swap(priority[i],priority[j]);
			}
		}
	}
	int btime=0;
	int min,k=1;
	for(int i=0;i<n;i++){
		btime+=bt[i];
		min=priority[k];
		for(int j=k;j<n;j++){
			if(priority[j]<min && at[j]<=btime){
			swap(at[k],at[j]);
			swap(bt[k],bt[j]);
			swap(priority[k],priority[j]);			
			}
		}
		k++;
	}
	cout<<"\n burst_time    Arrival_time   priority\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<bt[i]<<"\t   "<<at[i]<<"\t\t"<<priority[i]<<endl;
	}
	ct[0]=bt[0];
	for(int i=1;i<n;i++){
		ct[i]=ct[i-1]+bt[i];
	}	
	float total_tat=0;
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		total_tat+=tat[i];
	}	
	cout<<"\nAverage tat time : "<<total_tat/n<<endl;
	float total_wait=0;
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-bt[i];
		total_wait+=wt[i];
	}	
	cout<<"\nAverage waiting time : "<<total_wait/n<<endl;
	cout<<"\nBurst Arrival Waiting Turn-around complition_time\n";
	for(int i=0;i<n;i++){
		cout<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<endl;
	}
}

















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
	int temp_bt[100];
	for(int i=0;i<n;i++)
		temp_bt[i]=bt[i];
	int btime=0,smallest;
	int count=0;
	priority[n]=INT_MAX;
	while(count!=n){
		smallest=n;
		for(int j=0;j<n;j++){
			if(priority[j]<priority[smallest] && at[j]<=btime && bt[j]>0){
				smallest=j;
			}
		}
		bt[smallest]--;
		btime++;	
		if(bt[smallest]==0){
		       	count++;
		    	ct[smallest]=btime;
		 }
	}
	float total_tat=0;
	for(int i=0;i<n; i++){
		tat[i]=ct[i]-at[i];
		total_tat+=tat[i];
	}	
	cout<<"\nAverage tat time : "<<total_tat/n<<endl;
	float total_wait=0;
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-temp_bt[i];
		total_wait+=wt[i];
	}	
	cout<<"\nAverage waiting time : "<<total_wait/n<<endl;
	cout<<"\nBurst   Arrival   Waiting   Turn-around  complition_time\n";
	for(int i=0;i<n;i++){
		cout<<"  "<<temp_bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<endl;
	}
}

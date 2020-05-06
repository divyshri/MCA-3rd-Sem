#include<bits/stdc++.h>
using namespace std;
int main()
{
	int at[100],bt[100],ct[100],tat[100],wt[100];
	int n;
	cout<<"Enter the number of process";	
	cin>>n;
	cout<<"\nEnter the arrival time and burst time: ";
	for(int i=0;i<n;i++){
		cin>>at[i];
		cin>>bt[i];
	}	
	int temp_bt[100];
	for(int i=0;i<n;i++)
		temp_bt[i]=bt[i];
	int btime=0,smallest;
	int count=0;
	bt[n]=INT_MAX;
	while(count!=n)
	{
		smallest=n;
		for(int j=0;j<n;j++){
			if(bt[j]<bt[smallest] && at[j]<=btime && bt[j]>0){
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
	float total_turnaround_time=0;
	for(int i=0;i<n; i++){
		tat[i]=ct[i]-at[i];
		total_turnaround_time+=tat[i];
	}	
	cout<<"\nAverage tat time : "<<total_turnaround_time/n<<endl;
	float total_wait=0;
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-temp_bt[i];
		total_wait+=wt[i];
	}	
	cout<<"\nAverage waiting time : "<<total_wait/n<<endl;
	cout<<"\nBurst\t  Arrival\t  Waiting\t  Turn-around\n";
	for(int i=0;i<n;i++){
		cout<<"  "<<bt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
}

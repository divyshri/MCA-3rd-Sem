#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	int at[100],bt[100],pr[100],tat[100],wt[100],ct[100]={0};
	cout<<"Enter Arrival time, burst time and priority respectively"<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<"Arrival time for P"<<i<<"\t";
		cin>>at[i];
		cout<<"Burst time for P"<<i<<"\t";
		cin>>bt[i];
		cout<<"Priority P"<<i<<" \t";
		cin>>pr[i];
	}
 	int temp_bt[100];
	for(int i=0;i<n;i++)
		temp_bt[i] = bt[i];
	int btime=0,smallest;
	int count=0;
	pr[n] = INT_MAX;
	while(count!=n){
		smallest=n;
		for(int j=0;j<n;j++){
			if(pr[j] < pr[smallest] && at[j] <= btime && bt[j]>0)
				smallest = j;
		}
		bt[smallest]--;
		btime++;
		if(bt[smallest]==0){
			count++;
			ct[smallest]=btime;
		}
	}
	cout<<endl<<endl<<endl<<"P\tAT\tBT\tCT\tTAT\tWT"<<endl;
	for(int i=0;i<n;i++)
		cout<<i+1<<"\t"<<at[i]<<"\t"<<temp_bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
	double temp =0;
	for(int i=0;i<n;i++)
		temp+=tat[i];
	cout<<endl<<"Average Turn Around Time ----- "<<temp/n<<endl<<endl;	
	temp=0;
	for(int i=0;i<n;i++){
		temp+=wt[i];
	}
	cout<<endl<<"Average Waiting Time ----- "<<temp/n<<endl<<endl;
	return 0;

}

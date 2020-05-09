#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	int at[100],bt[100],pr[100],tat[100],wt[100],ct[100]={0},rem_time[100];
	cout<<"Enter Arrival time and burst timerespectively"<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<"Arrival time for P"<<i<<"\t";
		cin>>at[i];
		cout<<"Burst time for P"<<i<<"\t";
		cin>>bt[i];
	}
 	int time_quantum;
	cout<<"Enter time Quantum for the Processes"<<endl;
	cin>>time_quantum;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(at[i] > at[j]){
				swap(at[i],at[j]);
				swap(bt[i],bt[j]);
				cout<<"here 1"<<endl;
			}
		}
	}	
	for(int i=0;i<n;i++){
		rem_time[i] = bt[i];
		cout<<"here 2"<<endl;
	}
	int time=0,k=0,flag=0,count=0;
	while(count!=n){
		if(rem_time[k] <= time_quantum && rem_time[k] > 0){
			time += rem_time[k];
			rem_time[k] = 0;
			flag = 1;
		}			
		else if(rem_time[k]>0){
			rem_time[k] -= time_quantum;
			time += time_quantum;
		}
		if(rem_time[k] == 0 and flag == 1){
			count++;
			tat[k] = time - at[k];
			wt[k] = tat[k] - bt[k];
			flag = 0;
		}
		if(k == n-1)
			k=0;
		else if(at[k+1] <= time)
			k++;
		else
			k=0;


	}
	cout<<endl<<endl<<endl<<"P\tAT\tBT\tCT\tTAT\tWT"<<endl;
	for(int i=0;i<n;i++)
		cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
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

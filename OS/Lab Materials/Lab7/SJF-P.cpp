#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	int at[100],bt[100],tat[100],wt[100],ct[100]={0};
	cout<<"Enter Arrival time and burst time respectively"<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<"Arrival time for P"<<i<<"  ";
		cin>>at[i];
		cout<<"Burst time for P"<<i<<"  ";
		cin>>bt[i];
	}
	//Sorting According to the Arrival time
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(at[i] > at[j]){
				swap(at[i],at[j]);
				swap(bt[i],bt[j]);
			}
		}
	}
	int bt1[n];
	for(int i=0;i<n;i++)
		bt1[i] = bt[i];
	int min_diff = INT_MAX;
	for(int i=0;i<n-1;i++){
		if(min_diff>(at[i+1]-at[i]))
			min_diff = at[i+1] - at[i];
	}		
	int count=0,check=0,btime=0;
	while(count!=n){
		int j=0;
		int min = INT_MAX;
		for(int i=0;i<n;i++){
			if(btime>=at[i]){
				if(min>bt[i] and bt[i]!=0){
					min = bt[i];
					j=i;
				}			
			}
			else
				break;
		}
		bt[j] -= min_diff;
		btime += min_diff;
		if(bt[j]==0){
			count++;
			ct[j] = btime;
			tat[j] = ct[j] - at[j];
			wt[j] = tat[j] - bt1[j];
		}0
	}
	
	cout<<endl<<endl<<endl<<"P\tAT\tBT\tCT\tTAT\tWT"<<endl;
	for(int i=0;i<n;i++)
		cout<<i+1<<"\t"<<at[i]<<"\t"<<bt1[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
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

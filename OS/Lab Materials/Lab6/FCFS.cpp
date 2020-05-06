#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	int at[100],bt[100],tat[100],wt[100],ct[100]={0};
	cout<<"Enter Arrival time and burst time respectively"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Arrival time for P"<<i<<"  ";
		cin>>at[i];
		cout<<"Burst time for P"<<i<<"  ";
		cin>>bt[at[i]];
	}		
	ct[0] = bt[0];
	cout<<endl<<"Completion Time"<<endl<<endl;
	cout<<ct[at[0]]<<"  ";
	for(int i=1;i<n;i++){
		int t = (at[i] - ct[at[i-1]]);
		ct[at[i]] = (t>0)? ct[at[i-1]]+bt[at[i]] + t :  ct[at[i-1]]+bt[at[i]];
		cout<<ct[at[i]]<<"  ";
	}
	cout<<endl<<endl<<endl;
	cout<<endl<<endl<<"Turn Around Time is ------"<<endl;	
	double temp =0;
	for(int i=0;i<n;i++){
		tat[at[i]] = ct[at[i]] - at[i];
		cout<<endl<<"Turn around time for P"<<i<<"  "<<tat[at[i]];
		temp+=tat[at[i]];
	}
	cout<<endl<<"Average Turn Around Time ----- "<<temp/n<<endl<<endl;	
	temp=0;
	cout<<endl<<endl<<"Waiting Time is ------"<<endl;	
	for(int i=0;i<n;i++){
		wt[at[i]] = tat[at[i]] - bt[at[i]];
		cout<<endl<<"Waiting time for P"<<i<<"  "<<wt[at[i]];
		temp+=wt[at[i]];
	}
	cout<<endl<<"Average Waiting Time ----- "<<temp/n<<endl<<endl;
	return 0;
	                                                                
}

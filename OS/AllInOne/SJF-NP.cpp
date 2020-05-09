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
	int Bt = 0;
	Bt = at[0] + bt[0];
	ct[0] = Bt;
	tat[0] = ct[0] - at[0];
	wt[0] = tat[0] - bt[0];
	for(int i=1;i<n;i++){
		int min_index = i;
		int min = bt[i];			
		for(int j=i;j<n;j++){
			if(Bt>=at[j]){
				if(min>bt[j]){
					min_index = j;
					min = bt[j];					
				}
			}
		}
		swap(at[min_index],at[i]);
		swap(bt[min_index],bt[i]);
		if(Bt>=at[i]){
			ct[i] = bt[i] + Bt;
			tat[i] = ct[i] - at[i];
			wt[i] = tat[i] - bt[i];
			Bt = Bt + bt[i];
		}
		else{
			Bt = at[i] + bt[i];
			ct[i] = Bt;
			tat[i] = ct[i] - at[i];
			wt[i] = tat[i] - bt[i];	
		}
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

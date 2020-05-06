#include<bits/stdc++.h>
using namespace std;
int main()
{
		
	int at[100];
	int bt[100];
	int ct[100],tat[100],wt[100];
	int n;
	cout<<"Enter the number of process";	
	cin>>n;
	cout<<"\nEnter the arrival time and burst time: ";
	for(int i=0;i<n;i++){
		cin>>at[i];
		cin>>bt[i];
	}	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(at[i]>at[j]){
				swap(at[j],at[i]);
				swap(bt[j],bt[i]);
			}
		}
	}
	int btime=0,k=1,min;
	for(int i=0;i<n;i++)
	{
		btime=btime+bt[i];
		min=bt[k];
		for(int j=k;j<n;j++)
		{
			if(bt[j]<min && at[j]<=btime)
			{
				swap(bt[j],bt[k]);
				swap(at[j],at[k]);
			}
		}
		k++;
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
		wt[i]=wt[i]>0?wt[i]:0;
	}	
	cout<<"\nAverage waiting time : "<<total_wait/n<<endl;
	cout<<"\nBurst Arrival Waiting Turn-around\n";
	for(int i=0;i<n;i++){	
		cout<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
	}
}

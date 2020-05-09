#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,r;
	cout<<"Enter no. of processes : "<<endl;
	cin>>n;
	cout<<"Enter no. of Resources : "<<endl;
	cin>>r;
	int allo[n][r],max[n][r],need[n][r];
	int ava[r];
	cout<<"Enter allocation for the processes\n\n";
	for(int i=0;i<n;i++){
		cout<<"Enter Allocation for Process P"<<i<<endl;
		for(int j=0;j<r;j++)
			cin>>allo[i][j];
	}
	cout<<endl<<endl<<"Enter Maximum Available for the processes\n\n";
	for(int i=0;i<n;i++){
		cout<<"Enter Max Available for Process P"<<i<<endl;
		for(int j=0;j<r;j++){
			cin>>max[i][j];	
			need[i][j] = max[i][j] - allo[i][j];
		}
	}
	cout<<"Enter Available Space"<<endl;
	for(int i=0;i<r;i++)
		cin>>ava[i];
	cout<<"Allocation"<<endl;
	
	int check[n]={0},order[n],index=0,count=0,i=0;
	bool flag;
	
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(check[i]==0)
			{
				flag = true;
				for(int j=0;j<r;j++)
				{
					if(need[i][j]>ava[j])
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					//cout<<"P"<<i<<", ";
					order[index++] = i;
					for(int j=0;j<r;j++)
						ava[j] += allo[i][j];
					check[i] = 1;
				}
			}
		}
	}
	cout<<endl<<endl<<"Order of execution of the process is"<<endl<<endl;
	cout<<"< ";
	for(int i=0;i<n;i++)
		cout<<"P"<<order[i]<<", ";
	cout<<" >"<<endl<<endl<<endl;
}

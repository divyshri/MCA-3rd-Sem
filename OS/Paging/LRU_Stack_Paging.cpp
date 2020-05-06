#include<bits/stdc++.h>
int main()
{
	int n;
	cout<<"Enter total No of frames ";
	cin>>n;
	int frame[n];
	for(int i=0;i<n;i++)
		frame[i]=-1;
	int len;
	cout<<"Enter length of reference string ";
	cin>>len;
	int ref[len];
	cout<<"Enter the page string"<<endl;
	for(int i=0;i<len;i++)
		cin>>ref[i];
	int p=0;
	int count=0;
	for(int i=0;i<len;i++){
		int flag=0;
		for(int j=0;j<n;j++){
			if(frame[j]==ref[i]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout<<"hit\t\t-";
				for(int k=j;k>0;k--)
					frame[k]=frame[k-1];
		}
		else{
			cout<<"page fault\t-";
				for(int k=n-1;k>0;k--)
					frame[k]=frame[k-1];
		}
		frame[0]=ref[i];
		for(int j=0;j<n;j++)
			if(frame[j]!=-1)
				cout<<frame[j]<<" ";
		cout<<endl;
	}
}

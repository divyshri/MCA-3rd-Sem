#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter no. of processes : "<<endl;
	cin>>n;
	int allo[n],max[n],need[n],ava;
	cout<<"Enter allocation and Max Available for the process\n\n";
	for(int i=0;i<n;i++){
		cout<<"Enter Allocation and Max for Process P"<<i<<endl;
		cin>>allo[i]>>max[i];
		need[i] = max[i] - allo[i];
	}
	cout<<"Enter maximum available space"<<endl;
	cin>>ava;
	/*for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(need[i]>need[j]){
				swap(need[i],need[j]);
				swap(allo[i],allo[j]);
				swap(max[i],max[j]);
			}
		}	
	}*/	
	cout<<endl<<endl<<"Order of execution of the process is"<<endl<<endl;
	cout<<"< ";
	int count=0,i=0;
	while(count<n){		
		if(ava>=need[i] and need[i]!=0 ){
			cout<<"P"<<i<<", ";
			ava += allo[i];
			need[i] = 0;
			count++;
			i++;
		}
		else
			i++;
		if(i%n==0)
			i=0;
	}
	cout<<" >"<<endl<<endl<<endl;
	/*cout<<"P\tAllo\tMax\tNeed\tAval"<<endl;
	for(int i=0;i<n;i++){
		cout<<"P"<<i<<"\t"<<allo[i]<<"\t"<<max[i]<<"\t"<<need[i]<<"\t"<<ava<<endl;
		ava+=allo[i];
	}*/

}

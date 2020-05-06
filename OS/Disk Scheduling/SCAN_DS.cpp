#include <bits/stdc++.h> 
using namespace std; 

void SCAN(int arr[], int head,int size) 
{ 
    arr[size++] = head;
	sort(arr,arr+size);
	int head_loc;
	for(int i=0;i<size;i++){
		if(head==arr[i]){ 
			head_loc=i; 
			break;  
		}
	}
	cout << "Seek Sequence is" << endl; 
    for(int i=head_loc;i>=0;i--)
        cout << arr[i] << " "; 

    for(int i=head_loc+1;i<size;i++)
        cout << arr[i] << " "; 
    int total_count = head + arr[size-1]; 
    cout<<endl<<"Total number of seek operations = "<<total_count<<endl;    
} 
int main() 
{ 
	int n;
	cout<<"Enter total number of request"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Request"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
    int head; 
    cout<<"Enter Head"<<endl;
    cin>>head;
    SSTF(arr, head,n); 
} 

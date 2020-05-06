#include <bits/stdc++.h> 
using namespace std; 
void FCFS(int arr[], int head,int size) 
{ 
    int total_count = 0; 
    int distance, cur_req; 
    for (int i = 0; i < size; i++) { 
        cur_req = arr[i]; 
        distance = abs(cur_req - head); 
        total_count += distance; 
        head = cur_req; 
    }  
    cout << "Total number of seek operations = "<< total_count << endl;    
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
    FCFS(arr, head,n); 
    cout << "Seek Sequence is" << endl; 
    for(int i=0;i<n;i++)
        cout << arr[i] << " "; 
    return 0; 
} 

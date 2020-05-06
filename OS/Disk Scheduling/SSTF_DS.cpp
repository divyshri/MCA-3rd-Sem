#include <bits/stdc++.h> 
using namespace std; 
void SSTF(int arr[], int head,int size) 
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
	int small_i = head_loc-1;
    int large_i = head_loc+1;
	int small_diff = 0, large_diff = 0;
	int total_seek = 0, counter = size-1;
	cout << "Seek Sequence is" << endl; 
	while(counter>0) {
		small_diff = abs(arr[head_loc] - arr[small_i]);
		large_diff = abs(arr[large_i] - arr[head_loc]);
		if(small_diff < large_diff and small_i>=0) {
			total_seek += abs(arr[head_loc] - arr[small_i]);
			head_loc = small_i;
			cout << small_i << " : small index : = "<<total_seek<<endl; 
			small_i--;
		} 
        else{
			total_seek += abs(arr[large_i] - arr[head_loc]);
			head_loc = large_i;
			cout << arr[large_i] << " : large index : = "<<total_seek<<endl; 
			large_i++;
		}
		counter--;
	}
    cout<<endl<<"Total number of seek operations = "<< total_seek << endl;    
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
    return 0; 
} 

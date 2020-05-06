#include <bits/stdc++.h> 
using namespace std; 

void CLOOK(int arr[], int head,int size) 
{ 
    int seek_counter = 0;  
    vector<int> left_list, right_list,order; 
    for (int i = 0; i < size; i++) { 
        if (arr[i] < head) 
            left_list.push_back(arr[i]); 
        if (arr[i] > head) 
            right_list.push_back(arr[i]); 
    } 
  	sort(left_list.begin(), left_list.end()); 
    sort(right_list.begin(), right_list.end()); 
    int distance, cur_track;
    for (int i = 0; i < right_list.size(); i++) { 
        cur_track = right_list[i]; 
        order.push_back(cur_track); 
        distance = abs(cur_track - head); 
        seek_counter += distance; 
        head = cur_track; 
    } 
    seek_counter += abs(head - left_list[0]); 
    head = left_list[0];
    for (int i = 0; i < left_list.size(); i++) { 
        cur_track = left_list[i]; 
        order.push_back(cur_track); 
  		distance = abs(cur_track - head); 
        seek_counter += distance; 
  		head = cur_track; 
    } 
    cout << "Total number of seek operations = " << seek_counter << endl; 
    cout << "Seek Sequence is" << endl; 
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << endl; 
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

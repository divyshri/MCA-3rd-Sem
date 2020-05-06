#include <bits/stdc++.h>
using namespace std;

void LOOK(int arr[], int head, string init_dir, int size)
{
    int seek_counter = 0;
    
    vector<int> left_list, right_list,order;
    for (int i = 0; i < size; i++)    {
        if (arr[i] < head)
            left_list.push_back(arr[i]);
        if (arr[i] > head)
            right_list.push_back(arr[i]);
    }

    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());
    int loop = 2,distance, cur_track;
    while (loop--)
    {
        if (init_dir == "left_list")
        {
            for (int i = left_list.size() - 1; i >= 0; i--)
            
                cur_track = left_list[i],order.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_counter += distance;
                head = cur_track;
            }
            init_dir = "right_list";
        }
        else if (init_dir == "right_list")
        {
            for (int i = 0; i < right_list.s, i++)
             {
                cur_track = right_list[i],order.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_counter += distance;
                head = cur_track;
            }
            init_dir = "left_list";
        }
    }
    cout << "Total number of seek operations = " << seek_counter << endl; 
  
    cout << "Seek Sequence is" << endl; 
  
    for (int i = 0; i < order.size(); i++) { 
        cout << order[i] << endl; 
    }
    
}
int main()
{
    int n;
	cout<<"Enter total number of request"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Request"<<endl;      , seek_counter << endl;
	for(int i=0;i<n;i++) cout << "Seek Sequence is" << endl;
		cin>>arr[i];
    int head; 
    cout<<"Enter Head"<<endl;
    cin>>head;
    string init_dir;
    cout<<"Enter init_dir 'left_list' or 'right_list'"<<endl;
    cin>>init_dir;
    LOOK(arr, head, init_dir,n);
    return 0;
}

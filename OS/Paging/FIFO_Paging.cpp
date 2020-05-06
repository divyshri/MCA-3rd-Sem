#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total_pages;  // total number of pages
    int frame_size;  // frame size
    int page_faults; // to count no of page faults
    cout<<"Enter number of pages ";
    cin>>total_pages;
    cout<<"Enter size of frame  :   ";
    cin>>frame_size;
    int pr[total_pages]; // page name
    int fm[frame_size]; //frame
    cout<<"Enter page name :\n";
    for(int i=0 ; i<total_pages ; i++)
        cin>>pr[i];
    int s = 0,ss = 0;
    for(int i=0 ; i<frame_size ; i++)    
        fm[i] = -1;
    for(int i=0 ; i<total_pages ; i++){
        cout<<endl<<"Page :  "<<pr[i];
        if (i < frame_size){
            bool check = true;
            for (j = 0; j < frame_size; j++){	//Check for the presence of the page
                if (fm[j] == pr[i])
                    check = false;
            }
            if (check){						//Initially when page frame is empty
                fm[s] = pr[i];
                s = (s + 1) % frame_size;
             	page_faults++;
            }
        }
        else{
            check = true;
            for (int j=0 ; j<frame_size ; j++)
                if (fm[j] == pr[i])
                    check = false;
            if (check){
                fm[ss] = pr[i];
                page_faults++;
                ss = (ss + 1) % frame_size;
            }
        }
        cout<<"\t\t\t frame:";
        for(int j=0 ; j<frame_size ; j++)
            if (fm[j] > -1)
                cout<<"\t"<<fm[j];
    }

    cout<<endl<<endl<<" Total No. of Page Faults :  "<<page_faults;
}

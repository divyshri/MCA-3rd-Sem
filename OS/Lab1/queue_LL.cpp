#include<isostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;	
	Node(int data){
		this.data = data;
		next = NULL;
	}
	void insert()

}

int main()
{
	cout<<"Enter size of the Queue"<<endl;	
	cin>>size;
	while(1){
		int choice;
		cout<<endl<<endl;
		cout<<"Enter your choice to perform following actions"<<endl;
		cout<<"1. Insert element into the arr"<<endl;
		cout<<"2. Delete element from the arr"<<endl;
		cout<<"3. Display all the elements of the arr"<<endl;	
		cout<<"4. Exit the program"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				int data;
				if((rear == size-1 && front==0) || (front==rear+1) )
					cout<<"Element cannot be inserted the arr is full"<<endl;
				else{
					cout<<"Enter the value of the element that to be inserted"<<endl;
					cin>>data;
					if(front!=0 && rear==size-1)
						rear==-1;
					arr[++rear] = data;	
					if(front==-1)
						front++;
				}	
	
				break;
			case 2:
				if(front==-1)
					cout<<"No element to delete, the arr is empty"<<endl;
				else{
					cout<<endl<<" *** "<<arr[front++]<<" is delete from the arr"<<endl;
					if(front>rear)
						front=rear=-1;
				}
				break;
			case 3:
				if(front==-1)
					cout<<"No element to display, the arr is empty"<<endl;
				else{
					cout<<endl<<endl<<"arr elements are "<<endl;
					int f = front, r = rear;
					if(rear<=front){					
						while(f<=size-1)
							cout<<arr[f++]<<"  ";
						int z=0;
						while(z<=rear)
							cout<<arr[z++]<<"  ";
					}					
					else{
						f = front, r = rear;
						while(f<=r)
							cout<<arr[f++]<<"  ";
						
					}
				}
				break;		
			case 4:
				exit(0);
				break;
			default:
				cout<<endl<<"Invalid choice, please try again"<<endl;
				break;
		}	
	}

}

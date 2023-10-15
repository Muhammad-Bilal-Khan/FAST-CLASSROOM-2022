#include<iostream>
#include<string>
using namespace std;
//class for node
class Node{
	public:
	int data;
	Node *next;
};
//class for Singly Linked List
class SLL{
	public:
	//head pointer
	Node *head;
	Node *tail;
	public:
		//constructor
		SLL(){
			head=NULL;
			tail=NULL;
		}
		//destructor
	    ~SLL(){
		delete head;
		delete tail;
	    }

		                      /////methods////
		//for max length in case value is out of bound
		int max_length(){
			int count=0;
			Node* temp= new Node;
			temp=head;
			while(temp!=NULL){
				count=count+1;
				temp=temp->next;
			}
			return count;
		}
		
		//for checking if value exist
		bool exist(int val){
			bool checker=false;
			Node *temp=new Node;
			temp=head;
			while(temp->next!=NULL){
				if(temp->data==val){
					checker=true;
					break;
				}
				temp=temp->next;
			}
			if(temp->data==val){
				checker=true;
			}
			
			return checker;
		}
		
		                      /////insertion Methods/////
		
		//insertion at head
		void insert_at_front(int val){
			//temp node
			Node* temp=new Node;
			temp->data=val;
			temp->next=NULL;
			//checking if list was empty
			if(head==NULL){
			   head=temp;
			   tail=temp;
			   }
			else{
				temp->next=head;
			    head=temp;	
			   }
		}
		
		//insertion at the end
		void insert_at_end(int val){
			//temp Node
			Node *temp=new Node;
			temp->data=val;
			temp->next=NULL;
			//checking if head was empty
			if(head==NULL){
				head=temp;
				tail=temp;
			}
			else{
				tail->next=temp;
				tail=temp;
			}
		}

		//insertion at a given position
		void insert_at_postion(int val,int pos){
			int count;
			//temp Node
			Node *temp=new Node;
			temp->data=val;
			temp->next=NULL;
	        //nodes for iteration
			Node *prev,*curr;
			curr=head;
			count=max_length();
			//checking if pos is not less than 0
			if(pos<1||pos>count){
				cout<<"Invalid Position Entered! Position Must be between 0 and Max Length"<<endl;
			}
			//this will check if position is at front
			else if(pos==1){
				insert_at_front(val);
			}
			//this will work for the cases where the position is between head and  tail
			else{
			    for(int i=1;i<pos;i++){
				    prev=curr;
				    curr=curr->next;
			    }
			    temp->next=curr;
			    prev->next=temp;
		    }
		}

		                      /////Deletion Methods/////
		                      
		//deletion at front
		void delete_at_front(){
			//Creating a Temp Node
			Node *temp=new Node;
			//checking that head is not empty
			if(head==NULL){
				cout<<"There is no value at this postion"<<endl;
			}
			else{
			temp=head;
			head=head->next;
			temp->next=NULL;
			delete temp;
			}
		}
		
		//deletion at end
		void delete_at_end(){
			//Creating Curr and Prev Nodes
			Node *Curr,*Prev;
			//Checking if end Node is empty
			if(tail==NULL){
				cout<<"There is no value at this postion"<<endl;}
			else{
			Curr=head;
			while(Curr->next!=NULL){
				Prev=Curr;
				Curr=Curr->next;
			}
			tail=Prev;
			tail->next=NULL;
			//delete Curr;
		    }
		}
		
		//deletion at a point
		void delete_at_position(int pos){
			int count=0;
			count=max_length();
			Node *curr,*prev;
			curr=head;
			//checking that position is not out of bound
			if(pos<1||pos>count){
				cout<<"Posiiton is out of bound, it can only be between 0 to Max Length"<<endl;
			}
			//will work when position is the header
			else if(pos==1){
				delete_at_front();
			}
			//will work when position is between 1 and maxlength
			else{
				for(int i=1;i<pos;i++){
					prev=curr;
					curr=curr->next;
				}
				prev->next=curr->next;
				curr->next=NULL;
				delete curr;
			}
		}
		
		//deletion using value
		void delete_with_value(int val){
			bool check=false;
			check=exist(val);
			if(check==true){
				//cout<<"Value in Data"<<endl;
				Node *curr,*prev;
				curr=head;
				while(curr->data!=val){
					prev=curr;
					curr=curr->next;
				}
				//In case value is at head
				if(curr->data==head->data){
					delete_at_front();
				}
				//In case value is at tail
				else if(curr->data==tail->data){
					delete_at_end();
				}
				//In case value is in between
				else{
					prev->next=curr->next;
					curr->next=NULL;
					delete curr;
				}
			}
			else if(check==false){
				cout<<"Value not in Data"<<endl;
			}
		}
		
		                      //searching using a value//
				
		void search(int val){
			bool check;
			check=exist(val);
		if(check==true){
			//int variable for printing the position of the value 
			int counnt=1;
			//bool exist;
			Node *temp=new Node;
			temp=head;
			while(temp->data!=val){
				temp=temp->next;
				counnt=counnt+1;
			}
			if(temp->data==val){
				cout<<"Value: "<<val<<" Found!"<<endl;
			    cout<<"Position of value: "<<counnt<<endl;
			}
		}
		else{
			cout<<"Value is not here!"<<endl;
	    }
		}
		
		//displaying the list
		void display(){
			Node* temp= new Node;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
};
int main(){
	SLL obj;
	
	//checking to see if position is out of bound
	cout<<"When out of bound positions are entered"<<endl;
    obj.insert_at_postion(11,0);
    obj.insert_at_postion(12,50);
    cout<<endl;
    
	//checking insertion at front,end,position 1(front),
	obj.insert_at_front(2);
	obj.insert_at_front(9);
	obj.insert_at_front(10);
	obj.insert_at_front(1);
    obj.insert_at_end(3);
    obj.insert_at_end(4);
    obj.insert_at_postion(6,1);
    obj.insert_at_postion(10,2);
    obj.insert_at_front(5);
    obj.insert_at_front(4);
    
    //displaying
    cout<<"Before Deletion"<<endl;
    obj.display();
    cout<<endl;
    
    //deleting at front and end
    cout<<"After Deletion"<<endl;
    obj.delete_at_front();
    obj.delete_at_end();
    
    //displaying after deletion
    obj.display();
    cout<<endl;
    
    //deleting at a position
    obj.delete_at_position(1);
    cout<<"Deleted from position 1"<<endl;
    obj.delete_at_position(2);
    cout<<"Deleted from position 2"<<endl;
	obj.delete_at_position(2);
    cout<<"Deleted from position 2"<<endl;
    cout<<endl;

    //displaying after deletion at positions
    cout<<"Displaying after deleting at a position"<<endl;
    obj.display();
    cout<<endl;
    
    //deleting by val
    cout<<"Deleting by value"<<endl;
    obj.delete_with_value(6);
    cout<<"Deleted value 6"<<endl;
    obj.delete_with_value(3);
    cout<<"Deleted value 3"<<endl;
    obj.delete_with_value(2);
    cout<<"Deleted value 2"<<endl;
    obj.delete_with_value(9);
    cout<<"Deleted value 9"<<endl;
    cout<<endl;
    
    //deleting by val when val is not in data
    cout<<"When value to be deleted is not in the data"<<endl;
    obj.delete_with_value(40);
    cout<<endl;
    
    //displaying after deleting by value
    cout<<"Displaying after deleting with value"<<endl;
    obj.display();
    cout<<endl;
    
    //searching through value
    cout<<"Searching for value 4"<<endl;
    obj.search(4);
    obj.search(10);
    cout<<endl;
    
    //Creating an object for cheking delete ar front when there is no value there
    SLL obj1;
    
    //checking to see if position is out of bound
	cout<<"When out of bound positions are entered"<<endl;
    obj1.delete_at_front();
    obj1.delete_at_end();
    obj1.delete_at_position(100);
    cout<<endl;
	return 0;
}

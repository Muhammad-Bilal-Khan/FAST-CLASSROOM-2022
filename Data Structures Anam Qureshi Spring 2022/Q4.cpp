#include<iostream>
#include<string>
using namespace std;
//class of Node
class Node{
	//data
	public:
	char data;
	Node *Next;
		//constructor
	//default
		Node(){
			data=1;
			Next=NULL;
		}
	//parametrized
		Node(char d){
			data=d;
			Next=NULL;
		}
};
//class for Singly Linke List
class SLL{
	//attributes
	Node *head,*tail;
	public:
	//public methods
	
	//for checking if value exist
	bool exist(char val){
		bool checker=false;
		Node *temp=new Node;
		temp=head;
		while(temp->Next!=NULL){
			if(temp->data==val){
				checker=true;
				break;
			}
			temp=temp->Next;
		}
		if(temp->data==val){
			checker=true;
		}
		return checker;
		}
		
	//for max length in case value is out of bound
	int max_length(){
		int count=0;
		Node* temp= new Node;
		temp=head;
		while(temp!=NULL){
		count=count+1;
		temp=temp->Next;
		}
		return count;
	}
	             //constructors
	//default
	SLL(){
		head=NULL;
		tail=NULL;
	}
	             //destructor
	~SLL(){
                 //Inserting
		delete head,tail;
	}
    //at head
	void Insert_head(char d){
		//creating a temp Node
		Node *temp=new Node;
		temp->data=d;
		temp->Next=NULL;
		//when head is NULL
		if(head==NULL){
			temp->Next=head;
			head=temp;
			tail=temp;
		}
		//when head is Not NULL
		else{
			temp->Next=head;
			head=temp;
		}
	}
	 
	//at tail
	void Insert_tail(char D){
		//creating a temp Node
		Node *temp=new Node;
		temp->data=D;
		temp->Next=NULL;
		//Incase head is NULL means list doesn't exist and adding will mean adding to head
		if(head==NULL){
			Insert_head(D);
		}
		//Incase tail is not NULL will append
		else{
		tail->Next=temp;
		tail=temp;
		}
	}
	//at a position
	void Insert_Position(char Data,int val){
		Node *temp=new Node;
		temp->data=Data;
		temp->Next=NULL;
		Node *curr,*prev;
		curr=head;
		if(val==1){
		Insert_head(Data);	
		}
		else{
		//incase value exist between head and tail
		for(int i=1;i<val;i++){
			prev=curr;
			curr=curr->Next;
		}
		prev->Next=temp;
		temp->Next=curr;
	    }
	}
	
	            //Deletion
	//delete at head
	void delete_head(){
		if(head==NULL){
			cout<<"Head is already NULL"<<endl;
		}
		else{
			Node *prev;
			prev=head;
			head=head->Next;
			prev->Next=NULL;
			delete prev;
		}
	}
	//delete at tail
	void delete_tail(){
		if(tail==NULL){
			cout<<"Tail is already NULL"<<endl;
		}
		else{
			Node *curr;
			Node *prev;
			curr=head;
	        while(curr!=tail){
	        	prev=curr;
	        	curr=curr->Next;
			}
		tail=prev;
		prev->Next=NULL;
		curr->Next=NULL;
		delete curr;
		}
	}
	//delete at position
	void delete_position(int pos){
	int max;
	max=max_length();
	if(pos>max){
		cout<<"Position Out of Bound"<<endl;
	}
	else{
	
	if(pos==1){
		delete_head();
	}
	else if(pos==max){
		delete_tail();
	}
	else {
		Node *curr,*prev;
		curr=head;
		for(int i=1;i<pos;i++){
			prev=curr;
			curr=curr->Next;
		}
		prev->Next=curr->Next;
		curr->Next=NULL;
		delete curr;
	 }
	}
    }
	//delete by value
	void delete_by_val(char val){
		bool search;
		search=exist(val);
		if(search==false){
		cout<<"Value Doesn't Exist"<<endl;
        }
        else{
        	Node *prev,*curr;
        	curr=head;
        	while(curr->data!=val){
        		prev=curr;
        		curr=curr->Next;
			}
		if(curr->data==head->data){
			delete_head();
		}
		else if(curr->data==tail->data){
			delete_tail();
		}
		else{
		prev->Next=curr->Next;
		curr->Next=NULL;
		delete curr;
		}
	}	
	}
	
	            //Display
	void display(){
		Node *temp=new Node;
		temp->Next=NULL;
		temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->Next;
		}
	}
	            //Counting Nodes
int getCount(Node *head){
	struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->Next != NULL) {
        ptr2 = ptr1;
 
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->Next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->Next->data) {
                /* sequence of steps is important here */
                dup = ptr2->Next;
                ptr2->Next = ptr2->Next->Next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->Next;
        }
        ptr1 = ptr1->Next;
    }
    // Base Case
    if (head==NULL) {return 0;}
    else {return 1 + getCount(head->Next);}}
//getting head
Node* get_head(){
	return head;
}
};
int main(){
	//checking insertion
	SLL obj;
	cout<<"Insertion Operations"<<endl;
	obj.Insert_head('a');
	obj.Insert_head('b');
	obj.Insert_head('c');
	obj.Insert_tail('d');
	obj.Insert_tail('d');
	obj.Insert_tail('d');
	obj.Insert_tail('d');
	obj.Insert_Position('g',3);
	obj.Insert_Position('j',3);
	obj.Insert_Position('u',3);
	obj.Insert_head('y');
	obj.Insert_tail('z');
	obj.display();
	cout<<endl;
	cout<<"Total number of data without repetation ";
	cout<<obj.getCount(obj.get_head());
    cout<<endl;

	return 0;
}

#include<iostream>
#include<string>
using namespace std;
//class of Node
class Node{
	//data
	public:
	int data;
	Node *Next;
		//constructor
	//default
		Node(){
			data=1;
			Next=NULL;
		}
	//parametrized
		Node(int d){
			data=d;
			Next=NULL;
		}
};
//class for Singly Linke List
class CSLL{
	//attributes
	Node *head,*tail;
	public:
	//public methods
	
	//for checking if value exist
	bool exist(int val){
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
		while(temp!=tail){
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
	~CSLL(){
                 //Inserting
		delete head,tail;
	}
    //at head
	void Insert_head(int d){
		//creating a temp Node
		Node *temp=new Node;
		temp->data=d;
		temp->Next=NULL;
		//when head is NULL
		if(head==NULL){
			//temp->Next=head;
			head=temp;
			tail=temp;
			tail->Next=NULL;
			head->Next=NULL;
		}
		//when head is Not NULL
		else{
			temp->Next=head;
			tail->Next=temp;
			head=temp;
		}
	}

	//at tail
	void Insert_tail(int D){
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
		temp->Next=head;
		}
	}
	//at a position
	void Insert_Position(int Data,int val){
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
			tail->Next=head;
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
		tail->Next=head;
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
	void delete_by_val(int val){
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
		cout<<temp->data<<" ";
		temp=head->Next;
		while(temp!=head){
			cout<<temp->data<<" ";
			temp=temp->Next;
		}
	}
};
int main(){
	//checking insertion
	CSLL obj;
	cout<<"Insertion Operations"<<endl;
	obj.Insert_head(4);
	obj.Insert_head(3);
	obj.Insert_head(2);
	obj.Insert_tail(5);
	obj.Insert_Position(5,3);
	obj.Insert_Position(5,3);
	obj.Insert_Position(5,3);
	obj.Insert_head(5);
	obj.Insert_tail(10);
	obj.display();
    cout<<endl;
    
    //checking deletion
    cout<<"Deletion Operations"<<endl;
    obj.delete_by_val(3);
    obj.delete_head();
    obj.delete_tail();
    obj.delete_position(5);
    cout<<"After deletion Operations"<<endl;
    obj.display();
    cout<<endl;
	return 0;
}

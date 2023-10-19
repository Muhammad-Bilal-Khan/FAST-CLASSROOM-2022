#include<iostream>
#include<string>
using namespace std;


//class for Node
class Node{
//public:
public:
int data;
Node *prev,*next;
//constructor
Node(){
  prev=NULL;
  next=NULL;
}

};
//class for Doubly Linked List
class DLL{
//private

Node *head,*tail;
//public:
public:
       //constructor//
    //default
DLL(){
head=NULL;
tail=NULL;
}

       //destructor//
 ~DLL(){
 delete head;
 delete tail;
 }

       //methods//
//for max length
int max_length(){
int count;
Node*temp=new Node;
temp=head;
while(temp!=NULL){
count=count+1;
temp=temp->next;
}
return count;
}
//for checking if value exist
bool exist(int d){
  Node *temp=new Node;
  temp=head;
  while(temp!=NULL){
    if(temp->data==d)
     {return true;}
    temp=temp->next;
  }
 return false;
}
      //inserting//
 //inserting at head;
 void insert_at_head(int d){
 Node *temp=new Node;
 temp->data=d;
 temp->prev=NULL;
 temp->next=NULL;
 //temp->next=NULL;
 if(head==NULL){
 head=temp;
 tail=temp;
 }
 else{
 head->prev=temp;
 temp->next=head;
 head=temp;
 }
 }
 
 //inserting at tail;
 void insert_at_tail(int d){
 Node *temp=new Node;
 temp->next=NULL;
 temp->prev=NULL;
 temp->data=d;
 //
 if(tail==NULL){
 insert_at_head(d);
 }
else{
tail->next=temp;
temp->prev=tail;
tail=temp;
temp->next=NULL;}

}
 //inserting at a position
 void insert_at_position(int p,int d){
     int max_position;
     max_position=max_length();
     
     if(p>max_position||p<0){
         cout<<"Entered position out of range"<<endl;
     }
     else{
         
		 if(p==1){insert_at_head(d);}
         
		 else if(p==max_position){insert_at_tail(d);}
         
		 else{
         Node *temp=new Node;
         temp->next=NULL;
         temp->prev=NULL;
         temp->data=d;
         Node *curr,*Prev;
         curr=head;
         
		 for(int i=0;i<p;i++){
             Prev=curr;
             curr=curr->next;
             }
         
		 Prev->next=temp;
         temp->prev=Prev;
         temp->next=curr;
         curr->prev=temp;
  }
 }
}
 //deleting//
 //deleting at head
void delete_at_head(){
  if(head==NULL){cout<<"There is no value that exist here"<<endl;}
  else{
    Node *temp=new Node;
    temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete temp;
  }
}
 //deleting at tail
void delete_at_tail(){
if(tail==NULL){cout<<"There is no value that exist here"<<endl;}
     else{
        Node *abc;
        abc=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete abc;   
  }
}
 //deleting at position
void delete_at_position(int p){
  int max=max_length();
  if(p>max||p<0){
    cout<<"The entered position is out of range"<<endl;}
  else{
    Node *curr;
    curr=head;
    if(p == 1){
    	delete_at_head();	
	}
	else if(p==max){
		delete_at_tail();
	}
	else {
		for(int i=0;i<p-1;i++,curr=curr->next);
    	curr->prev->next = curr->next;
    	curr->next->prev = curr->prev;	
    	delete curr;
	}
    
  }
}
 //deleting by value
void delete_by_val(int v){
  bool check;
  check=exist(v);
  if(check==false){cout<<"This value doesn't exist"<<endl;}
  else{
    Node *curr,*Prev,*temp;
    curr=head;
    while(curr!=NULL){
      if(curr->data==v){
        Prev=curr->prev;
        temp=curr->next;
        Prev->next=temp;
        temp->prev=Prev;
        curr->next=NULL;
        curr->prev=NULL;
      }
    }
  }
}
 //searching
void search(int val){
  bool check;
  check=exist(val);
  if(check==false){
    cout<<"Value not found"<<endl;
  }
  else{
    cout<<"Value found"<<endl;
  }
}
 //printing
 void print(){
	 Node *temp;
	 temp=head;
	 cout<<endl;
	 while(temp!=NULL){
		 cout<<temp->data<<" ";
		 temp=temp->next;
 	}
 }
 
  void reverse_print(){
	 Node *temp;
	 temp=tail;
	 cout<<endl;
	 while(temp!=NULL){
		 cout<<temp->data<<" ";
		 temp=temp->prev;
 	}
 }
//oveloading for concatination 
DLL &operator+( DLL& b){
tail->next=b.head;
b.head->prev=tail;
tail=b.tail;
}

//overloading for assining
DLL &operator =(DLL&a){
	tail=NULL;
	head=NULL;
    Node *temp;
    temp=a.head;
	while(temp!=NULL){
		insert_at_tail(temp->data);
		temp=temp->next;
	}
}
///
void swap(struct Node *a, struct Node *b){
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}

//sorting
void sort(){
    int sp;
    Node *curr;
    Node *prev = NULL;
    /* Checking for empty list */
    if (head == NULL)
        return;
    do{
    sp=0;
        curr=head;
        while(curr->next!=prev){
        if(curr->data>curr->next->data){ 
                swap(curr,curr->next);
                sp=1;
            }
            curr=curr->next;
        }
        prev=curr;
    }
    while(sp);
}
///
};
using namespace std;
int main(){
	DLL M;
	DLL L;
	M.insert_at_head(1);
	M.insert_at_tail(3);
	M.insert_at_tail(5);
	M.insert_at_tail(7);
	M.insert_at_tail(9);
	M.print();
	L.insert_at_head(2);
	L.insert_at_tail(4);
	L.insert_at_tail(6);
	L.insert_at_tail(8);
	L.insert_at_tail(10);
	L.print();
	DLL N;
	N=M+L;
	N.print();
	N.sorting();
	N.print();
}

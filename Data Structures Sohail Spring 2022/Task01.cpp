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

//parametrized
// DLL(int d){
// Node *temp=new Node;
// temp->data=d;
// temp->next=NULL;
// temp->prev=NULL;
// }
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
 
};
using namespace std;
int main(){
DLL obj;
//inserting
obj.insert_at_head(1);
obj.insert_at_tail(2);
obj.insert_at_tail(3);
obj.insert_at_tail(4);
obj.insert_at_position(3,6);
obj.insert_at_position(1,10);
obj.insert_at_position(6,67);
obj.insert_at_position(99,99);
obj.print();
obj.reverse_print();
//deleting
cout<<endl;
obj.delete_at_head();
obj.print();
cout<<endl;
obj.delete_at_tail();
obj.print();
obj.delete_at_position(4);
//obj.print();
obj.print();
obj.reverse_print();
}

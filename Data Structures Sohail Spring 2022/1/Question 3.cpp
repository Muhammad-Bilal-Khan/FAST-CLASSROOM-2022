#include<iostream>
#include<string>
using namespace std;
//class for Node
class Node{
//public:
public:
string F_name,l_name,email,cell number,day,address;
int issue;
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
bool exist(string d){
  Node *temp=new Node;
  temp=head;
  while(temp!=NULL){
    if(temp->day==d)
     {return true;}
    temp=temp->next;
  }
 return false;
}
      //inserting//
 //inserting at head;
 void insert_at_head(int i,string d,string f,string l,string e,string add,string c,string e){
 Node *temp=new Node;
 temp->email=e;
 temp->issue=i;
 temp->cell=c;
 temp->F_name=f;
 temp->l_name=l;
 temp->cell=c;
 temp->address=add;
 temp->day=d;
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
 void insert_at_tail(int i,string d,string f,string l,string e,string add,string c,string e){
 Node *temp=new Node;
 temp->email=e;
 temp->issue=i;
 temp->cell=c;
 temp->F_name=f;
 temp->l_name=l;
 temp->cell=c;
 temp->address=add;
 temp->day=d;
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
 void insert_at_position(int p,int i,string d,string f,string l,string e,string add,string c,string e){
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
         temp->email=e;
         temp->issue=i;
       temp->cell=c;
 temp->F_name=f;
 temp->l_name=l;
 temp->cell=c;
 temp->address=add;
 temp->day=d;
 temp->next=NULL;
 temp->prev=NULL;
 temp->data=d;
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
 //printing
 void print(){
	 Node *temp;
	 temp=head;
	 cout<<endl;
	 while(temp!=NULL){
		 cout<<temp->day<<" "<<temp->email<<" "<<temp->issue<<" "<<temp->cell<<" "<<temp->F_name<<" "<<temp->l_name<<" "<<temp->cell<<" "<<temp->address<<" "<<temp->day<<" ";
		 temp->next=NULL;
		 temp->prev=NULL;
		 temp=temp->next;
 	}
 }
 
};
using namespace std;
int main(){

}


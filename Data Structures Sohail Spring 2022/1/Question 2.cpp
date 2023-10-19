#include <iostream>
#include <string>
using namespace std;
//
class Node{
	public:
	Node *prev,*next;
	int data;
};
class DLL{
	Node *head,*tail;
	public:
		//checking data
		bool is_even(int d){
			if((d%2)==0){
				return true;
			}
			else{
				return false;
			}
		}
		bool is_empty(){
			if(head==NULL){
				return true;
			}
		}
		//
		DLL(){
			head=NULL;
			tail=NULL;
		}
		//
		DLL(int d){
			bool result;
			result=is_even(d);
			if(result==true){
				add_tail(d);
			}
			else{
				add_head(d);
			}
		}
		//adding
		void add_head(int d){
			Node *temp=new Node;
			temp->next=NULL;
			temp->prev=NULL;
			temp->data=d;
			bool check;
			check=is_empty();
			if(check == true){		
				head=temp;
			    head->next=NULL;
			    head->prev=NULL;
				tail=temp;
			    tail->next=NULL;
			    tail->prev=NULL;
	 		}
			else{
				head->prev=temp;
				temp->next=head;
				head=temp;
			}
	
		}
		//tail
		void add_tail(int d){
			Node *temp=new Node;
			temp->data=d;
			temp->next=NULL;
			temp->prev=NULL;
			bool check;
			check=is_empty();
			if(check==true){
				add_head(d);
			}
			else{
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
			}
		}
		//printing
		void print(){
			Node *temp;
		    temp=head;
		    while(temp!=NULL){
		    	cout<<temp->data<<" ";
		    	temp=temp->next;
			}
		}
		//
		void enter(int d){
			bool result;
			result=is_even(d);
			if(result==true){
				add_tail(d);
			}
			else if(result==false){
				add_head(d);
			}
		}

};
int main(){
	DLL obj;
	obj.enter(2);
	obj.enter(4);
	obj.enter(7);
	obj.enter(10);
	obj.print();
    return 0;
}


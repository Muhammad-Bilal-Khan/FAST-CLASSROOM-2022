#include<iostream>
#include<string>
using namespace std;
//class
class Min{
	//values
	int Size;
	int *ptr;
	public:
	//constructor
	Min(int L){
	Size=L;
	ptr=new int[Size];}
	Min(){Size=5;
	ptr=new int[Size];}
	//methods
	void Minima(){
	for(int a=0;a<Size;a++){
		if(a==0&&ptr[a]<ptr[a+1]){cout<<ptr[a]<<"Index of realative minima is  "<<a<<endl;}
		else if(a==Size&&ptr[a]<ptr[a-1]){cout<<ptr[a]<<"Index of realative minima is "<<a<<endl;}
		else if(ptr[a]<ptr[a-1]&&ptr[a]<ptr[a+1]){cout<<ptr[a]<<"Index of realative minima is "<<a<<endl;}
		}
	}
	//taking values for the array form the user
	void Input(){
		for(int a=0;a<Size;a++){cout<<"Enter the value for: "<<a<<endl;
		cin>>ptr[a];}
	}
//destructor
~Min(){delete []ptr;}
};
int main(){
	Min a(8);
	a.Input();
	a.Minima();
	return 0;
}

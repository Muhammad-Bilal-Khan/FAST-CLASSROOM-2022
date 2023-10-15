#include<iostream>
#include<string>
using namespace std;
//class
class safe_array{
	int Row,Col;
	int *ptr;
	int count=0;
	public:
//constructor
	safe_array(int r,int c){
	Row=r;
	Col=c;
	ptr=new int[Row*Col];}
//method for taking input in the array
	void Input(){
	int V,count;
	count=0;
	for(int x=0;x<Row;x++){
	for(int z=0;z<Col;z++){
	cout<<"Enter value "<<x<<z<<endl;
	cin>>V;
	if(V==1){count=count+1;}
	*(ptr+x*Col+z)=V;}}
	cout<<"The Numbers of 1 in array are "<<count<<endl;}
//oveloading () for safe array	
	int operator ()(int r,int c){
	if(r<0||r>=Row||c<0||c>=Col){
	cout<<"Invalid index "<<endl;}
	else{cout<<*(ptr+r*Col+c)<<endl;}
	}
};
int main(){
	safe_array A(3,3);
	A.Input();
	return 0;
}

#include<iostream> 
#include<ctime>
#include<time.h>
#include<cstdlib>
#include<string>
using namespace std; 
class Sort{
	int *ptr;
	int Size;
	public:
	//constructor
	Sort(){
	Size=50;
	ptr=new int[Size];}
	//methods
	void ShellSort() {
   	int gap,j,k;
   	int count=0;
   	for(gap=Size/2;gap>0;gap=gap/2){ 
   	for(j=gap;j<Size;j++) {
   	for(k=j-gap;k>=0;k-= gap) {
    if(ptr[k+gap]>=ptr[k]){
    count ++;
    break;}
    else{
    int t;
    t=ptr[k+gap];
    ptr[k+gap]=ptr[k];
    ptr[k]=t;
    continue;	}}}}
  	cout<<"Number of comparisions set is "<<count<<endl;
	}
	void Random(){
	srand(time(0));
	for(int i=0;i<Size;i++){
	ptr[i]=(rand()%100);}}
	void print(){
	for(int i=0;i<Size;i++){
	cout<<ptr[i]<<",";}}
	void fullsorted(){
	for(int i=0;i<Size;i++){
	ptr[i]=i;}}
	void nearly_sorted(){
	int count =0;
	int p=0;
	for(int i=0;i<Size/2;i++){
	ptr[i]=i;
	++p;}
	for(int j=(Size/2);j<Size;j++){
	ptr[j]=count++;
	++p;}}
	void Dup(){
	for(int i=0;i<Size;i=i+2){
	ptr[i]=i;
	ptr[i+1]=i;			
	}}
};
int main(){
	Sort a;
	a.Random();
	cout<<"Random array"<<endl;
	a.ShellSort();
	a.print();
	cout<<"sorted array"<<endl;
	a.fullsorted();
	cout<<endl;
	a.ShellSort();
	a.print();
	cout<<endl;
	cout<<"Nearly soretd array"<<endl;
	a.nearly_sorted();
	a.ShellSort();
	a.print();
	cout<<endl;
	cout<<endl;
	a.Dup();
	a.ShellSort();
	a.print();
	return 0;
}

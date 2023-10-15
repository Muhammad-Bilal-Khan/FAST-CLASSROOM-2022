#include<iostream>
using namespace std;

int main()
{
    bool array[5][5] = {{false, true, false, true, true},{true, false, true, false, true},{false, true, false, false, false},{true, false, false, false, true},{true, true, false, true, false}};
    int r1 = 0, r2 = 0;
    bool flag = false;
    cout<<"Enter rows of which you want to find common friends: " << endl;
    cout<<"ROW: ";
    cin>>r1;
    cout<<"ROW: ";
    cin>>r2;
    for(int i = 0; i < 5; i++)
    {if(array[r1][i] == true && array[r2][i] == true){ cout << "Common Friend: " << i;
    flag = true;}}
    if(flag == false)
    { cout << "No Common friends!";}
}

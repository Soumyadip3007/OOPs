#include<iostream>
using namespace std;

int add(int a, int b)
{
    while(b!=0)
    {
        int data=a&b;
        a=a^b;
        b=data<<=1;
    }
    return a;
}
int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Sum is: "<<add(a,b)<<endl;
    return 0;
}
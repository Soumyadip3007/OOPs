#include<iostream>
using namespace std;
int sub(int a, int b)
{
    while(b!=0)
    {
        int data=(~a)&b;
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
    cout<<"Difference is: "<<sub(a,b)<<endl;
    return 0;
}
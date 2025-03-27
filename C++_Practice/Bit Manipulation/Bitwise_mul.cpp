#include<iostream>
using namespace std;

int mul(int a, int b)
{
    int result=0;
    while(b!=0)
    {
        if(b&1)
        {
            result+=a;
        }
        a<<=1;
        b>>=1;
    }
    return result;
}
int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Product is: "<<mul(a,b)<<endl;
    return 0;
}
#include<iostream>
using namespace std;

class A
{
    protected:
        int a;
    public:
        void get_a()
        {
            cout<<"Value of a is "<<a<<endl;
        }
};

class B
{
    protected:
        int b;
    public:
        void get_b()
        {
            cout<<"Value of b is "<<b<<endl;
        }
};

class C: public A, public B
{
    protected:
    int c;
    public:
    void get_c()
    {
        cout<<"Value of c is "<<c<<endl;
    }
    C(int a,int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main()
{
    cout<<"This is a simple example of multiple inheritance."<<endl;
    C obj(10,20,30);
    obj.get_a();
    obj.get_b();
    obj.get_c();
    return 0;
}
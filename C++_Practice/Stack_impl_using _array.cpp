#include <bits/stdc++.h>
using namespace std;


class Stack
{
    int *arr;
    int size;
    int top;
    public:
    Stack(int s)
    {
        size=s;
        top=-1;
        arr= new int[s];
        cout<<"Stack Implementation using Array\n";
    }
    void push(int x)
    {
        if(top==(size-1))
        {
            cout<<"Stack is Full can't push "<<x<<endl;
            return;
        }
        top++;
        arr[top]=x;
        cout<<"Pushed "<<x<<" into the stack"<<endl;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty can't pop element "<<endl;
            return;
        }
        cout<<"Popped "<<arr[top]<<" from the stack"<<endl;
        top--;
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty can't find peek element "<<endl;
            return-1;
        }
        return arr[top];
    }
    bool Isempty()
    {
        cout<<"Stack is Empty"<<endl;
        return top==-1;
    }
    ~Stack()
    {
        delete[] arr;
        cout<<"Stack is deleted"<<endl;
    }
};
int main() {
	// your code goes here
    Stack s(4);
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    
    s.push(10);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.Isempty();
}
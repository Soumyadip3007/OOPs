#include <bits/stdc++.h>
using namespace std;


class Queue
{
    int *arr;
    int size;
    int top;
    int cnt;
    public:
    Queue(int s)
    {
        size=s;
        top=0;
        cnt=0;
        arr= new int[s];
        cout<<"Queue Implementation using Array\n";
    }
    void push(int x)
    {
        if(cnt==size)
        {
            cout<<"Queue is Full can't push "<<x<<endl;
            return;
        }
        if(cnt==0) //first element
        {
            arr[top]=x;
            cout<<"Pushed "<<x<<" into the queue"<<endl;
        }
        else 
        {
            arr[cnt]=x;
            cout<<"Pushed "<<x<<" into the queue"<<endl;
        }
        cnt++;
    }
    void pop()
    {
        if(cnt==0)
        {
            cout<<"queue is empty can't pop element "<<endl;
            return;
        }
        cout<<"Popped "<<arr[top]<<" from the queue"<<endl;
        top++;
        cnt--;//decreasing count;
        if(cnt==0)
        {
            top=0;
        }
    }
    int peek()
    {
        if(cnt==0)
        {
            cout<<"queue is empty can't find peek element "<<endl;
            return-1;
        }
        return arr[top];
    }
    bool Isempty()
    {
        return cnt==0;
    }
    ~Queue()
    {
        delete[] arr;
        cout<<"Queue is deleted"<<endl;
    }
};
int main() {
	// your code goes here
    Queue q(4);
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    
    q.push(10);
    
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    if (q.Isempty()) 
    {
        cout << "Queue is Empty" << endl;
    }
}
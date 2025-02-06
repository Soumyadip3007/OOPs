#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data, Node* next)
    {
        this->data=data;
        this->next=next;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void printLL(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            cout<<temp->data;
            break;
        }
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
Node* swapPairs(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* temp=head->next;
    head->next=swapPairs(temp->next);
    temp->next=head;
    return temp;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    cout<<"Before Swapping: ";
    printLL(head);
    head=swapPairs(head);
    cout<<"After Swapping: ";
    printLL(head);
    return 0;
}
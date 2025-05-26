//Deleting any node(except the last one) without using the head pointer
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void PrintLL(Node* head)
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

void deleteNode(Node* dummy)
{
    if(dummy==NULL || dummy->next==NULL)
    {
        cout<<"Not Possible!"<<endl;
        return;
    }
    Node* temp=dummy->next;
    dummy->data=temp->data;
    dummy->next=temp->next;
    free(temp);
}

int main() {
	// your code goes here
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    cout<<"Original Linkedlist:"<<endl;
    PrintLL(head);
    Node* dummy=head->next->next;
    cout<<"Deleting "<<dummy->data<<"..."<<endl;
    deleteNode(dummy);
    PrintLL(head);
}
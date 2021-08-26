#include<bits/stdc++.h>
using namespace std;
class Node{

    //public data members of a  class, declaring the data memebrs of node of linkedlist
    public:
    int data;
    Node* next;
// explicit parameterized constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};


int length(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;  
    }

    return count;
}

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;

    while(data!=-1)
    {
        Node* newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void printNode(Node* head)
{
    int count=0;
    while(head!=NULL)
    {
        cout<<"index "<<count<<", "<<head->data<<endl;
        head=head->next;
        count++;
    }

    cout<<endl;
}
Node* kthNodeend(Node* head, int k)
{
    Node* kthnode=head;
    Node* ptemp = head;
    int count = 0;
    while(count!=(k-1))
    {
        ptemp=ptemp->next;
        count++;
    }
    // for(int i=0;i<(k-1);i++)
    //   ptemp=ptemp->next;
    while(ptemp->next!=NULL)
    {
        ptemp=ptemp->next;
        kthnode=kthnode->next;
    }
    return kthnode;
}

int main()
{
    Node* head = takeInput();
    // int imp = length(head);
    //printNode(head);

    Node* knode = kthNodeend(head, 2);
    cout<<knode->data;

}

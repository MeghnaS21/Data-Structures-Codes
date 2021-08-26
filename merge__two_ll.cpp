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

Node* mergesortll(Node* head1, Node* head2)
{
    Node* fh = NULL; 
    Node* ft = NULL;
    // fh = (head1->data<head2->data)?(head1):(head2);
    if(head1->data < head2->data){
        fh = head1;
        head1=head1->next;
    }
    else{
        fh = head2;
         head2=head2->next;
    }
    ft = fh;

    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            ft->next = head1;
            head1=head1->next;
        }
        else{
            ft->next = head2;
            head2 = head2->next;
        }
        ft = ft->next;
    }
    // if(head1!=NULL)
    //   ft->next = head1;
    // else 
    //   ft->next = head2;

    ft->next = (head1!=NULL)? head1:head2;
    return fh;
}

int main()
{
    Node* head1 = takeInput();
    Node* head2 = takeInput();

    Node* head3 = mergesortll(head1, head2);
    // printNode(head1);
    // printNode(head2);
    //int imp = length(head);
    printNode(head3);

}

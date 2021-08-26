#include<iostream>
using namespace std;

class Node{

    //public data members of a  class, declaring the data memebrs of node of linkedlist
    public:
    int data;
    Node* next;
// explicit default constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node* insertNode(Node* &head, int i, int data)
{
    Node* newNode = new Node(data); //create new node with the data
    int count=0;   //intialise counter with zero(0)
    Node* temp=head; // for traversing till (i-1)th position, we need to use temporary head

    //case-1 :  we want to insert at 0th position
    if(i==0)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }

    while(temp!=NULL && count<(i-1))
    {
        temp = temp->next;
        count++;
    }

    if(temp!=NULL)
    {
        newNode->next = temp->next;
        temp->next=newNode;
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
}

int main()
{
    Node* n1 = new Node(1);
    Node* head = n1;

    Node* n2= new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    // printNode(head);
    
    insertNode(head, 7, 10);
    // printNode(insertNode(head, 0, 10));
    printNode(head);
}
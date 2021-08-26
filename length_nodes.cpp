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

int Length(Node* head)
{
    Node* temp=head;
    if(temp==NULL)
    {
        return 0;
    }
    int small=Length(temp->next);
    int output=1+small;
    return output;
}

// Node* insertNode(Node* &head, int i, int data)
// {
//     Node* newNode = new Node(data); //create new node with the data
//     int count=0;   //intialise counter with zero(0)
//     Node* temp=head; // for traversing till (i-1)th position, we need to use temporary head

//     //case-1 :  we want to insert at 0th position
//     if(i==0)
//     {
//         newNode->next=head;
//         head=newNode;
//         return head;
//     }

//     while(temp!=NULL && count<(i-1))
//     {
//         temp = temp->next;
//         count++;
//     }

//     if(temp!=NULL)
//     {
//         newNode->next = temp->next;
//         temp->next=newNode;
//     }

//     return head;
//}
/*
Node* deleteNode(Node* &head, int i)
{
    Node* temp=head;
    int count=0;

    if(i==0)
    {
        Node* a= head;
        head=head->next;
        delete a;
        return head;
    }

    while(temp!=NULL && count<(i-1))
    {
        temp = temp->next;
        count++;
    }

    if(temp!=NULL)
    {
        Node* a= temp->next;
        temp->next=a->next;
        delete a;  
   }

   return head;
} */

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

int main()
{
    Node* head = takeInput();



    // Node* n1 = new Node(1);
    // Node* head = n1;

    // Node* n2= new Node(2);
    // Node* n3 = new Node(3);
    // Node* n4 = new Node(4);
    
    // n1->next=n2;
    // n2->next=n3;
    // n3->next=n4;
    // printNode(head);
    
    // insertNode(head, 2, 10);
    // printNode(insertNode(head, 0, 10));
    printNode(head);

    cout<<Length(head);

    // deleteNode(head, 3);
    // printNode(head);
}
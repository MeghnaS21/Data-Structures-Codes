#include<iostream>
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

Node* deleteNode(Node* &head, int i)
{
   if(head==NULL)
    {
        return head; //in that return head;
    }

    //Base case
    //--- if deletion takes palce at 0 then
    if(i==0)
    {
        Node* a = head; // create new node
        head=head->next; //swap the head and newNode position
        delete a;
        return head;
    }
    //else if i>0 then call recursively the function

    head->next=deleteNode(head->next, i-1);
    return head;
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

int main()
{
    Node* head = takeInput();
    printNode(head);
    deleteNode(head, 2);
    printNode(head);
}

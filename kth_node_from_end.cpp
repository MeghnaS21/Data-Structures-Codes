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

int length(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

Node* kthNode(Node* head, int k)
{
    Node* temp=head;
    Node* curr=head->next;

    while(temp!=NULL && length(curr) != (k-1) )
    {
        if(length(curr) < (k-1) )
              cout<<"Few ";
            else{
                curr= curr->next;
            }
            temp=temp->next;
    }
    return temp;
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

    Node* kNode = kthNode(head, 3);
    cout<<kNode->data;
}

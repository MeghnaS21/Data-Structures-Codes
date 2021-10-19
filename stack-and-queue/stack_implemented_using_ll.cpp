#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stack{
    public:
    Node<T> *head;
    int size;

    stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return head==NULL;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        if(isEmpty())
        {
            head = newNode;
            size++;
        }
        else{
            newNode->next =head;
            head = newNode;
            size++;
        }

    }

    T pop()
    {
        T ans =0;
        if(isEmpty())
        {
            cout<<"Can't pop. Stack is empty"<<endl;
            return 0;
        }
        else{
            ans = head->data;
            Node<T> *a = head;
            head = head->next;
            size--;

            delete a;
        }
        return ans;
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }

        return head->data;
    }

    int getSize()
    {
        return size;
    }

};

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.getSize()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    s.push(40);
    cout<<s.top()<<endl;
}

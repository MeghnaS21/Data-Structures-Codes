
#include<iostream>
#include<climits>
using namespace std;

class StackusingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
     StackusingArray(int totalsize)
     {
         data = new int[totalsize];
         nextIndex=0;
         capacity = totalsize;
     }

     int size()
     {
         return nextIndex;
     }

     bool isempty()
     {
         return nextIndex==0;
     }

     void push(int element)
     {
         if(nextIndex==capacity)
         {
             cout<<"stack is full. Cannot push!!";
             return;
         }
         data[nextIndex]=element;
         nextIndex++;
     }
     int pop()
     {
         if(isempty())
         {
             cout<<"empty"<<endl;
             return INT_MIN;
         }
         nextIndex--;
         return data[nextIndex];
     }
     int top()
     {
         if(isempty())
         {
             cout<<"Stack is empty. Cannot read top element"<<endl;
             return INT_MIN;
         }
         
         return data[nextIndex-1];
     }
};

int main()
{
    StackusingArray stack1(5);
    stack1.push(20);
    stack1.push(30);
    stack1.push(10);
    stack1.push(40);
    stack1.push(60);
    cout<<stack1.size()<<endl;
    stack1.pop();
    cout<<stack1.size()<<endl;
    cout<<stack1.top()<<endl;
}

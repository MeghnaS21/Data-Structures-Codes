//code
#include<iostream>
#include<cmath>
using namespace std;

class queue{
    int *data;
    int nextIndex;
    int frontIndex;
    int size;
    int capacity;
    public:

    queue(int totalsize)
    {
        data = new int[totalsize];
        nextIndex = 0;
        frontIndex = -1;
        size = 0;  
        capacity=totalsize;
    }

    bool isEmpty()
    {
        if(size==0)
          return true;
        else
          return false;
    }

    void enqueue(int val)
    {
        if(size==capacity){
            cout<<"full"<<endl;
            return;
        }
        data[nextIndex]=val;
        nextIndex = (nextIndex+1)%capacity;
        size++;

        if(frontIndex==-1)
           frontIndex=0;
    
    }

    void dequeue()
    {
        int ans = 0;
        if(isEmpty()){
            return ;
        }
        ans = data[frontIndex];
        frontIndex = (frontIndex+1)%capacity;
        size--;
    }

    int getSize()
    {
        return size;
    }

    int front()
    {
        return data[frontIndex];
    }
};

int main()
{
    queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout<<"front "<<q1.front()<<endl; 
    q1.enqueue(40);
    q1.enqueue(50); 
    q1.dequeue();
    cout<<"front "<<q1.front()<<endl; 
    q1.enqueue(40);


    cout<<q1.getSize(); //2
}

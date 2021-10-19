#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverse(stack<int> &s1, stack<int> &s2)
{
    if(s1.size()==0)  //base case: if stack is empty
      return;          //return nothing
    
    int ans = s1.top();  //store the top of original stack
    s1.pop();            //pop it from the original stack
    reverse(s1, s2);         //recursive call on the original stack i.e. 10, 20, 30, 40;
                            //we will get s1 as 40, 30, 20, 10

    while(s1.empty()==0){   //copied s1 to s2
        s2.push(s1.top());
        s1.pop();
    }                      // s2 = {10, 20, 30, 40}
    s2.push(ans);          // pushing my top from the original array i.e. ans=50
                           // now s2 is {10, 20, 30, 40, 50}

    while(s2.empty()==0){    //now pushing s2 to s1;
        s1.push(s2.top());
        s2.pop();
    }                    // s1 = {50, 40, 30, 20, 10}
}

void takeinput(stack<int> &s1)
{
    int data=0;
    int size=0;
    cin>>size;
    while(size--){
        cin>>data;
        s1.push(data);
    }
}

void printstack(stack<int>s1)
{
    while(s1.empty()==0)
    {
        cout<<s1.top()<<endl;
        s1.pop();
        
    }
}
int main()
{
    stack<int>s1;
    stack<int>s2;
    takeinput(s1);
    //printstack(s1);
    reverse(s1, s2);
    
    printstack(s1);
}

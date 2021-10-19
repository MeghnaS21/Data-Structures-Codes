#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<int>s1;

void insert_at_bottom(int last)
{
    if(s1.size()==0)   // as soon as the s1 is empty. 
       s1.push(last);   //push top element from the reverse function
    else{
        char anss = s1.top();   //store the top of reverse s1 in function call;
        s1.pop();
        insert_at_bottom(last);
        s1.push(anss);   // as soon as the fucntion reaches the base case.
                         // this line will start pushing (anss) stored in function call stack
        }
}

void reverse(stack<int> &s1)
{
    if(s1.size()==0)  //base case: if stack is empty
      return;          //return nothing
    
    int ans = s1.top();  //store the top of original stack
    s1.pop();            //pop it from the original stack
    reverse(s1);         //recursive call on the original stack i.e. 10, 20, 30, 40;
                             // we will get s1 as 40, 30, 20, 10
    insert_at_bottom(ans);         //now to insert the ans at the bottom, call this fucntion
                            
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
    takeinput(s1);
    //printstack(s1);
    reverse(s1);
    
    printstack(s1);
}

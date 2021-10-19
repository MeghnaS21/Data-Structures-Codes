#include<iostream>
using namespace std;
int getsetbit(int n, int b)
{
   int ans=0;
   while(n)
   {
      ans+=n%b;
      n/=b;
   }
   return ans;
}

int main()
{    
    //ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
     {   
         int n,l,r;
    cin>>n>>l>>r;
    int ans=getsetbit(n,l);
    int ans1=l;
    for(int i=l;i<=min(l+90000,r);i++)
    {  
       int d=getsetbit(n,i);
       if(d<ans)
       {
         ans=d;
         ans1=i;
       }
    }
    for(int i=r;i>=max(r-90000,l);i--)
    {  
       int d=getsetbit(n,i);
       if(d<ans)
       {
         ans=d;
         ans1=i;
       }
    }
    cout<<ans1<<endl;
   } 
   return 0;
}
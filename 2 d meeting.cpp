#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<long double> coordinate_x(200);
vector<long double> coordinate_y(200);
// void run()
// {
//    fast;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt","w",stdout);
//    #endif // ONLINE_JUDGE 
// }
ll findmin(long double a,long double b)
{
  ll sumation=0;
  for(int i=0;i<n;i++)
      {
          if(a==coordinate_x[i]&&b==coordinate_y[i])
            sumation+=0;
          else if(a==coordinate_x[i]||b==coordinate_y[i])
            sumation+=1;
          else if(abs(a-coordinate_x[i])==abs(b-coordinate_y[i]))
            sumation+=1;
          else
            sumation+=2; 
      }
      
      return sumation;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
      cin>>n;
      for(int i=0;i<n;i++)
      {
        cin>>coordinate_x[i];
      }
      for(int i=0;i<n;i++)
      {
        cin>>coordinate_y[i];
      }
    //   for(int o=0;o<100;o++)
    //   {
    //     //just for fun
    //     ll pqr=o;
    //   }
      ll minoperation=1e18;
      long double a=0,b=0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          a=coordinate_x[i];
          b=coordinate_y[j];

          minoperation=min(minoperation,findmin(a,b));

          a=0.5*(coordinate_y[i]+coordinate_x[i]+coordinate_y[j]-coordinate_x[j]);
          a=0.5*(coordinate_y[i]+coordinate_x[i]-(coordinate_y[j]-coordinate_x[j]));
          
          minoperation=min(minoperation,findmin(a,b));
          
          b=coordinate_y[i];
          a=coordinate_y[j]+coordinate_x[j]-b;
          
          minoperation=min(minoperation,findmin(a,b));
          
          a=b-(coordinate_y[j]-coordinate_x[j]);
          
          minoperation=min(minoperation,findmin(a,b));
          
          a=coordinate_x[i];
          b=coordinate_y[j]-coordinate_x[j]+b;
          
          minoperation=min(minoperation,findmin(a,b));
          
          b=coordinate_y[j]+coordinate_x[j]-b;
          
          minoperation=min(minoperation,findmin(a,b));
          
          a=0.5*(coordinate_x[i]+coordinate_x[j]);
          b=0.5*(coordinate_y[i]+coordinate_y[j]);
          
          minoperation=min(minoperation,findmin(a,b));


        }
      }
      
    cout<<minoperation<<endl;
    for(int i=0;i<400;i++)
    {
      coordinate_x[i]=0;
      coordinate_y[i]=0;
    }  
  }
}
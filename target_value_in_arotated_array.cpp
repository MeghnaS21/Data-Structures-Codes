#include<bits/stdc++.h>
using namespace std;

void find_target_val(int arr[], int n, int target_val)
{
    //find minimum element inorder to get the starting point of the non rotated array
    int min=INT_MAX, min_index=0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]<min){
            min=arr[i];
            min_index=i;
        }
    }
    cout<<"min index="<<min_index<<endl;

    //search target value's present index
    int target_val_index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target_val)
        {
            target_val_index=i;
        }
    }
    cout<<"target_val_index="<<target_val_index<<endl;

    //find the key, using which our array was rotated earlier
    int key=n-min_index;
    cout<<"key=" <<key<<endl;

    //search and print the target index of the target value

    if(target_val_index < min_index)
    {
        // for(int i=0;i<min_index;i++)
        // {
        //     if(arr[i]==target_val)
        //     {
        //         cout<<(min_index-i-2);
        //     }
        // }
        cout<<(min_index+target_val_index-4);
    }
    else if(target_val_index > min_index)
    {
        for(int i=min_index;i<n;i++){
         if(arr[i]==target_val)
         {
            cout<<target_val_index-min_index;
         }
    }
    }
    else{
        cout<<"0";
    }
}

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[10]={4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n=10;
    int target_val=5;

    find_target_val(arr, n, target_val);
    // display(arr, n);


    
}
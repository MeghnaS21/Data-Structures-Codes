#include <iostream>
using namespace std;

//swaps two numbers

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



void bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
int main() {
    int arr[1000000];
    int n=5;
    
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr, n);
    for(int i=0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}

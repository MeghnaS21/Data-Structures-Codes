#include <iostream>
using namespace std;
int main() {
    char arr[100];
    gets(arr);

    for(int i =0 ; arr[i]!='\0';i++){
        if(arr[i]>='A' && arr[i] <= 'Z'){
            arr[i] += 32;
        }
        else{
            arr[i] -= 32;
        }
    }
    cout<<arr;
}

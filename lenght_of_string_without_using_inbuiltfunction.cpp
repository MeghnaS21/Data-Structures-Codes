#include <iostream>
#include<string>
using namespace std;
int main() {
    char arr[30];
    gets(arr);
    int size=0;
    for(int i=0 ; arr[i] != '\0' ; i++){
        ++size;
    }
    cout<<size;
}

#include <iostream>
using namespace std;
#define MAX 4
void inputmatrix(int matrix[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cin>>matrix[i][j];
        }
    }
}
void printmatrix(int matrix[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rowmajorPrint(int matrix[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    int matrix[MAX][MAX];
    inputmatrix(matrix);
    //printmatrix(matrix);
    rowmajorPrint(matrix);
}

#include <iostream>
#include<queue>
using namespace std;
template<typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode* left;
    binarytreenode* right;

    binarytreenode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int sum(binarytreenode<int>* root){
    if(root==NULL)
      return 0;
    else
      return root->data+sum(root->left)+sum(root->right);
}
binarytreenode<int>* takeinput()
{
    int rootdata;
    cin>>rootdata;
    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        binarytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            binarytreenode<int>* leftchild = new binarytreenode<int>(leftdata);
            front->left = leftchild;
            pendingnodes.push(leftchild);
        }
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            binarytreenode<int>* rightchild = new binarytreenode<int>(rightdata);
            front->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}
int main() {
    binarytreenode<int>* root = takeinput();
    cout<<sum(root);

    
}

#include<iostream>
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

     ~binarytreenode(){
         delete left;
         delete right;
     }
};

int countnodes(binarytreenode<int>* root){
    if(root==NULL)
      return 0;
    
    return 1+countnodes(root->left)+countnodes(root->right);
}
binarytreenode<int>* takeINput(){
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1) 
       return NULL;
    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        binarytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            binarytreenode<int>* leftchild = new binarytreenode<int>(leftchilddata);
            front->left = leftchild;
            pendingnodes.push(leftchild);
        }
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
            binarytreenode<int>* rightchild = new binarytreenode<int>(rightchilddata);
            front->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

int main(){
    binarytreenode<int>* root = takeINput();
    //print(root);
    cout<<countnodes(root);

}
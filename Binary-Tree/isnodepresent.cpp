#include <iostream>
#include<queue>
using namespace std;
template<typename T>
class bianrytreenode{
    public:
     T data;
     bianrytreenode* left;
     bianrytreenode* right;

     bianrytreenode(T data){
         this->data = data;
         left = NULL;
         right = NULL;
     }
     ~bianrytreenode(){
         delete left;
         delete right;
     }
};

bool findnode(bianrytreenode<int>* root, int x){
    if(root==NULL) 
      return false;

    else if(root->data == x)
      return true;

    else return findnode(root->left, x) || findnode(root->right, x);
}
bianrytreenode<int>* takeinput()
{
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1)  
      return NULL;
    
    bianrytreenode<int>* root = new bianrytreenode<int>(rootdata);
    queue<bianrytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        bianrytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();

        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            bianrytreenode<int>* leftnode= new bianrytreenode<int>(leftchild);
            front->left = leftnode;
            pendingnodes.push(leftnode);
        }

        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            bianrytreenode<int>* rightnode = new bianrytreenode<int>(rightchild);
            front->right= rightnode;
            pendingnodes.push(rightnode);
        }
    }
    return root;
}
int main() {
    bianrytreenode<int>* root = takeinput();
    if(findnode(root, 6))
      cout<<"Yes present";
    else
      cout<<"Not present";
}

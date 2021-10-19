#include<iostream>
using namespace std;
template<typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode* left;
    binarytreenode* right;

    binarytreenode(T data){
        this->data = data;
        left =NULL;
        right = NULL;
    }

    ~binarytreenode()
    {
        delete left;
        delete right;
    }
};
void printrecur(binarytreenode<int>* root){
    if(root==NULL)
      return;

    cout<<root->data;
    if(root->left!= NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printrecur(root->left);
    printrecur(root->right);
}

binarytreenode<int>* takeinput(){
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1) return NULL;
    binarytreenode<int>* root= new binarytreenode<int>(rootdata);
    binarytreenode<int>* left = takeinput();
    binarytreenode<int>* right = takeinput();
    root->left=left;
    root->right=right;
    return root;
}

int main(){
    binarytreenode<int>* root = takeinput();
    printrecur(root);
}

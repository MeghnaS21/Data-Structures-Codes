#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTrees{
    public:
    T data;
    BinaryTrees* left;
    BinaryTrees* right;

    BinaryTrees(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTrees<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;

    if(rootData==-1)
      return NULL;

    BinaryTrees<int>* root = new BinaryTrees<int> (rootData);

    queue<BinaryTrees<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTrees<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child"<<front->data<<endl;
        int leftCHildData;
        cin>>leftCHildData;

        if(leftCHildData != -1){
            BinaryTrees<int> * child = new BinaryTrees<int>(leftCHildData);
            front->left = child;

            pendingNodes.push(child);
        }
        cout<<"Enter right child"<<front->data<<endl;
        int rightCHildData;
        cin>>rightCHildData;

        if(rightCHildData != -1){
            BinaryTrees<int> * child = new BinaryTrees<int>(rightCHildData);
            front->right = child;

            pendingNodes.push(child);
        }
    }
    return root;
}

void PrintNode(BinaryTrees<int>* root){
     if(root==NULL)
       return;

    cout<<root->data<<": ";

    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data;
    }

    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    PrintNode(root->left);
    PrintNode(root->right);
}




int main(){

    BinaryTrees<int>* root = takeInputLevelWise();
    //PrintNode(root);

    char ino[]= {4, 2, 5, 8, 6, 9, 3, 7};
    char pre[]= { 1, 2, 4, 5, 3, 6, 8, 9, 7};

    int len = sizeof(in) / sizeof(in[0]);

    Buildtree(ino, pre, 0, len-1);
}
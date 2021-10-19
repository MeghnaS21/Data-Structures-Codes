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
    //cout<<"Enter root data"<<endl;
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

        //cout<<"Enter left child"<<front->data<<endl;
        int leftCHildData;
        cin>>leftCHildData;

        if(leftCHildData != -1){
            BinaryTrees<int> * child = new BinaryTrees<int>(leftCHildData);
            front->left = child;

            pendingNodes.push(child);
        }
        //cout<<"Enter right child"<<front->data<<endl;
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

void range(BinaryTrees<int>* root, int min, int max)
{
    if(root==NULL)
          return;
         
        if(root->data > min)
          range(root->left, min, max);
         
        if(root->data >= min && root->data <= max)
          cout<<root->data<<", ";
        
        range(root->right, min, max);
}

BinaryTrees<int>* BalancedBST(int arr[], int start, int end){
    if(start>end)
      return NULL;

    int mid = start +(end - start)/2;
    BinaryTrees<int>* root = new BinaryTrees<int>(arr[mid]);

    root->left= BalancedBST(arr, start, mid-1);
    root->right = BalancedBST(arr, mid+1, end);

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
    int arr[]={1,2,3,4,5,6,7};

    BinaryTrees<int>* root = BalancedBST(arr, 0, 6);
    PrintNode(root);
    //range(root, 2, 9);
}
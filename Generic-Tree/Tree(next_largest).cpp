#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector< TreeNode<T>* > children; //vector with TreeNode type pointer is created, name-> children

    TreeNode(T data)
    {
        this->data = data; //initialize the data portion of TreeNode object with the passed data
    }

    //-----TAKE INPUT FROM USER----
    
};
//template <typename T>
TreeNode<int> * TakeInputLevelWise()
    {
        int rootData=0;
        cout<<"Enter root data "<<endl;
        cin>>rootData;
        TreeNode<int>* root = new TreeNode<int>(rootData);

        queue<TreeNode<int>*> pendingNodes;
        pendingNodes.push(root);

        while(pendingNodes.size()!=0)
        {
            TreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            cout<<"Enter number of children of front data "<<front->data<<endl;
            int numchild;
            cin>>numchild;

            for(int i=0;i<numchild;i++)
            {
                int childdata;
                cout<<"Enter child of "<<front->data<<endl;
                cin>>childdata;
                TreeNode<int>* child = new TreeNode<int> (childdata);
                front->children.push_back(child);
                pendingNodes.push(child);
            }
        }
        //cout<<root->children->data;
        return root;
    }

    //------PRINT TREE NODES---

    void printTree(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ": ";
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ", ";
        }
        cout << endl;
        for (int i = 0; i < root->children.size(); i++)
        {
            printTree(root->children[i]);
        }
    }

    void preorder(TreeNode<int>* root)
    {
        if(root==NULL)
          return;

        cout<<root->data<<" ";
        for(int i=0;i<root->children.size();i++)
        {
            preorder(root->children[i]);
        }
    }

    void postorder(TreeNode<int>* root)
    {
        if(root==NULL)
          return;
        for(int i=0;i<root->children.size();i++)
        {
            postorder(root->children[i]);
        }

        cout<<root->data<<" ";
    }
    
   
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int n) {
	if(root == NULL || root -> children.size() == 0){
        return root;
    }
    
    int compare = INT_MAX;
    TreeNode<int>* ansNode = NULL;
    
    if(root -> data > n && root -> data < compare){
        compare = root -> data;
        ansNode = root;
    }
    
    for(int i=0; i<root -> children.size(); i++){
        TreeNode<int>* recNode = getNextLargerElement(root -> children[i], n);
        if(recNode != NULL){
            if(recNode -> data > n && recNode -> data < compare){
            ansNode = recNode;
            compare = recNode -> data;
            }
        }
    }
    return ansNode;
}


int main()
{
    TreeNode<int> * root =  TakeInputLevelWise();
    printTree(root);
    //preorder(root);
    cout<<endl;
    //postorder(root);
    //cout<<node_max(root);
    TreeNode<int>* ans = getNextLargerElement(root, 10);
    cout<<ans->data;
    return 0;
}



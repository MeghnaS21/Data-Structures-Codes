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
        left=NULL;
        right=NULL;
    }
    ~binarytreenode()
    {
        delete left;
        delete right;
    }
};

void print(binarytreenode<int>* root){
    queue<binarytreenode<int>*> pendingNodes; //create a queue called pendingnodes
	pendingNodes.push(root); //push the root into the queue 
	while (pendingNodes.size() != NULL) { //do the operations inside the block till the queue isn't empty
		binarytreenode<int>* front = pendingNodes.front();  //create a front node separately and extract the front or the topmost element of the queue
		cout<<front->data << ":"; //now print the data of the front node
		pendingNodes.pop();  //pop it form the queue
		if (front->left != NULL) {   //check for the left child
			cout << "L:" << front->left->data << ","; //print the left child's data
			pendingNodes.push(front->left);  //now push that left child inside of queue so that the same child can act as the root node for next level
		}
		else { //if left child is not present that is -1 
			cout << "L:" << -1 << ","; //then pritn -1
		}
        //repeat the steps same as the left child
		if (front->right != NULL) {
			cout << "R:" << front->right->data;
			pendingNodes.push(front->right);
		}
		else {
			cout << "R:" << -1;
		}
		cout << "\n";
	}
}

binarytreenode<int>* takeinput(){
    int rootdata; 
    cin>>rootdata; //insert root data at each level
    if(rootdata==-1)
      return NULL; //check if rootdata = -1 then return the control
    binarytreenode<int>* root = new binarytreenode<int>(rootdata); //create a root node of root data
    queue<binarytreenode<int>*> pendingnodes; //create a queue called pending nodes
    pendingnodes.push(root);    //push the rootdata into it
    while(pendingnodes.size()!=0){ //check till the queue size is not 0
        binarytreenode<int>* front = pendingnodes.front(); //extract the front element of queue
        pendingnodes.pop(); //pop it from the original stack
        int leftchilddata; //now create a left child for this root node at the same level
        cin>>leftchilddata;
        if(leftchilddata!=-1){ //check if it is present the do further execution
            binarytreenode<int>* leftchild = new binarytreenode<int>(leftchilddata); //create a left child node
            front->left = leftchild; //connect the root to its left child
            pendingnodes.push(leftchild); //now push this left child into the queue so that it can behave as a root for next level
        }
        //same with the right node or right child
        int rightchildda;  
        cin>>rightchildda;
        if(rightchildda!=-1){
            binarytreenode<int>* rightchild = new binarytreenode<int>(rightchildda);
            front->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root; //now return the root the root node of main :78
} 

int main(){
    binarytreenode<int>* root = takeinput(); //here:74
   print(root);
    delete(root);
}

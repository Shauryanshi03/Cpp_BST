#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

bool search(BinaryTreeNode<int> *root,int x){
    if(root==NULL){
        return false;
    }

    if(root->data==x)
    return true;

    if(root->data > x){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}

int main(){

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(5);
    root->left=new BinaryTreeNode<int>(3);
    root->right=new BinaryTreeNode<int>(7);
    root->left->left=new BinaryTreeNode<int>(2);
    root->left->right=new BinaryTreeNode<int>(4);
    root->right->left=new BinaryTreeNode<int>(6);
    root->right->right=new BinaryTreeNode<int>(8);

    int x=6;

    if(search(root,x))
    cout<<"Element found";

    else
    cout<<"Element not found";

    return 0;
}

/*ITERATIVE WAY

bool search(BinaryTreeNode<int> *root,int x){
 
BinaryTreeNode<int> *temp=root;

    while(temp!=NULL){
    if(temp->data==x){
    return true;
    }
    if(temp->data > x){
    temp=temp->left;
    }
    else{
    temp=temp->right;
    }
    
return false;
}

*/
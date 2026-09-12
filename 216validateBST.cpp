#include<iostream>
#include<climits>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

bool isBST(Node* root,int min,int max){
    if(root==NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validate(Node *root){
    return isBST(root,INT_MIN,INT_MAX);
}

int main(){

    Node*root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(7);
    root->right->left=new Node(12);
    root->right->right=new Node(20);

    if(validate(root))
    cout<<"Valid BST";
    else
    cout<<"Not a valid BST";
    
    return 0;
}
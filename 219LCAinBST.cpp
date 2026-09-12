#include<iostream>
#include<map>
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

Node* LCA(Node* root,Node* P,Node* Q){
    if(root==NULL)
    return NULL;

    if(root->data < P->data && root->data < Q->data)
    return LCA(root->right,P,Q);

    if(root->data > P->data && root->data > Q->data)
    return LCA(root->left,P,Q);

    return root;
}

int main(){

    Node*root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);

    Node* P=root->left->left;
    Node* Q=root->left->right;

    Node* ans=LCA(root,P,Q);

    cout<<"LCA : "<<ans->data<<endl;

    return 0;
}

/*ITERATIVE WAY
Node* LCA(Node* root,Node* P,Node* Q){
    if(root==NULL)
    return NULL;

    while(root!=NULL){
    if(root->data < P->data && root->data < Q->data)
    root=root->right;

    else if(root->data > P->data && root->data > Q->data)
    root=root->left;

    else{
    return root;
    }
  }
}
*/
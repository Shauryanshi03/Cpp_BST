#include<iostream>
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

int solve(Node* root,int& i,int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k)
    return root->data;

    return solve(root->right,i,k);
}

int kthsmallest(Node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

int main(){

    Node*root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);

    int k=3;
    cout<<"Kth smallest : "<<kthsmallest(root,k);

    return 0;
}
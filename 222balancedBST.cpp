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

void inorder(Node* root,vector<int> &in){
    if(root==NULL)
    return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* inordertoBST(int s,int e, vector<int> &in){
    if(s>e)
    return NULL;

    int mid=(s+e)/2;
    Node* root=new Node(in[mid]);
    root->left=inordertoBST(s,mid-1,in);
    root->right=inordertoBST(mid+1,e,in);
    return root;
}

Node* balancedBST(Node* root){
    vector<int> inorderval;
    inorder(root,inorderval);
    
    return inordertoBST(0,inorderval.size()-1,inorderval);
}

int main(){
    Node*root=new Node(10);
    root->left=new Node(8);
    root->left->left=new Node(6);
    root->left->left->left=new Node(4);
    root->left->left->left->left=new Node(2);
    
    Node* ans=balancedBST(root);

    vector<int> inorderval;
    inorder(ans,inorderval);

    cout<<"Inorder : ";

    for(int i=0;i<inorderval.size();i++){
        cout<<inorderval[i]<<" ";
    }
    
    return 0;
}
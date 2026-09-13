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

Node* solve(vector<int> &preorder,int mini,int maxi,int &i){
    if(i>=preorder.size())
    return NULL;

    if(preorder[i]<mini || preorder[i]>maxi)
    return NULL;

    Node* root=new Node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}

Node* BST(vector<int> &preorder){

    int mini=INT_MIN;
    int maxi=INT_MAX;

    int i=0;
    return solve(preorder,mini,maxi,i);
}

int main(){
    vector<int> preorder={10,5,2,7,25,12,20};
    Node* root=BST(preorder);

    cout<<"BST created successfully";

    return 0;
}
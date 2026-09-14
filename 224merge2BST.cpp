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

vector<int> mergearrays(vector<int> a,vector<int> &b){
    vector<int> ans(a.size()+b.size());

    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }
    return ans;
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

Node* mergeBST(Node* root1,Node* root2){
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergedarray=mergearrays(bst1,bst2);

    int s=0,e=mergedarray.size()-1;
    return inordertoBST(s,e,mergedarray);
}

int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);

    Node* root2=new Node(5);
    root2->left=new Node(4);
    root2->right=new Node(6);

    Node* root=mergeBST(root1,root2);
    cout<<"Merged BST created";

    return 0;
}
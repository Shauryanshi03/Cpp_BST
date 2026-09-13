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

bool twosum(Node* root,int target){
    vector<int> inorderval;
    inorder(root,inorderval);

    int i=0,j=inorderval.size()-1;

    while(i<j){
        int sum=inorderval[i]+inorderval[j];

        if(sum==target)
        return true;

        else if(sum>target)
        j--;

        else
        i++;
    }
    return false;
}

int main(){
 Node*root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);

    int target=9;

    cout<<"two sum : "<<twosum(root,target)<<endl;

    return 0;
}
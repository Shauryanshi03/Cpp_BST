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

pair<int,int> PredecessorSuccessor(Node* root,int key){
    Node* temp=root;
    int pred=-1;
    int succ=-1;

    while(temp->data!=key){
        if(temp->data > key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }

    Node* lefttree=temp->left;
    while(lefttree!=NULL){
        pred=lefttree->data;
        lefttree=lefttree->right;
    }

    Node* righttree=temp->right;
    while(righttree!=NULL){
        succ=righttree->data;
        righttree=righttree->left;
    }

    pair<int,int> ans=make_pair(pred,succ);
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

    int key=3;
    pair<int,int> ans=PredecessorSuccessor(root,key);

    cout<<"Predecessor : "<<ans.first<<endl;
    cout<<"Successor : "<<ans.second<<endl;

    return 0;
}
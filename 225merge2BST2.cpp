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

void convertintoDLL(Node* root,Node* head){
    if(root==NULL){
    return;
    }

    convertintoDLL(root->right,head);
    root->right=head;
    if(head!=NULL)
        head->left=root;

    head=root;

    convertintoDLL(root->left,head);
}

Node* mergetwoLL(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
    }

     while(head2!=NULL){
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
    }
    return head;
}

int countnodes(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

Node* sortedLLtoBST(Node* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }

    Node* left=sortedLLtoBST(head,n/2);
    Node* root=head;
    root->left=left;
    head=head->right;

    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
}

Node* mergeBST(Node* root1,Node* root2){
    Node* head1=NULL;
    convertintoDLL(root1,head1);
    head1->left=NULL;

    Node* head2=NULL;
    convertintoDLL(root2,head2);
    head2->left=NULL;

    Node* head=mergetwoLL(head1,head2);

    return sortedLLtoBST(head,countnodes(head));
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
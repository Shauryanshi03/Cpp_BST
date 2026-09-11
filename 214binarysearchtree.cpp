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

void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelordertraversal(Node *root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
          cout<<temp->data<<" ";
          if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

Node* insertIntoBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

Node* minval(Node* root){
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxval(Node* root){
    Node* temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deletenode(Node* root,int val){
    if(root==NULL){
        return root;
    }

    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child left
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //1 child right
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletenode(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left=deletenode(root->left,val);
        return root;
    }
    else{
        root->right=deletenode(root->right,val);
        return root;
    }
}

void takeinput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){
    Node* root=NULL;

    cout<<"Enter data to create BST"<<endl;
    takeinput(root);

    cout<<"Printing the BST"<<endl;
    levelordertraversal(root);

    cout<<"Printing inorder"<<endl;
    inorder(root);

    cout<<endl<<"Printing preorder"<<endl;
    preorder(root);

    cout<<endl<<"Printing postorder"<<endl;
    postorder(root);

    cout<<endl<<"Min value is "<<minval(root)->data<<endl;
    cout<<"Max value is "<<maxval(root)->data<<endl;

    root=deletenode(root,30);
    cout<<"Printing the BST"<<endl;
    levelordertraversal(root);

    cout<<"Printing inorder"<<endl;
    inorder(root);

    cout<<endl<<"Printing preorder"<<endl;
    preorder(root);

    cout<<endl<<"Printing postorder"<<endl;
    postorder(root);

    cout<<endl<<"Min value is "<<minval(root)->data<<endl;
    cout<<"Max value is "<<maxval(root)->data<<endl;

    return 0;
}

//input=50 20 70 10 30 90 110 -1
//complexity of insertion is O(logn)
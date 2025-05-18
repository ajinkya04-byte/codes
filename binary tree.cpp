#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n=new node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(struct node* root){
    
    if(root!=NULL){
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data;

    }
    
}

void inorder(struct node* root){
    if (root!=NULL)
    {
        postorder(root->left);
        cout<<" "<<root->data;
        postorder(root->right);

    }
    
}

int main()
{
    struct node* n=createNode(7);
    struct node* n1=createNode(71);
    struct node* n2=createNode(72);
    struct node* n3=createNode(4);
    struct node* n4=createNode(41);
    struct node* n5=createNode(42);
    

    n->left=n1;
    n->right=n2;

    n1->left=n3;
    n1->right=n4;
    
    n2->left=n5;
    n2->right=NULL;

    // preorder(n);
    // postorder(n);
    // inorder(n);

    
    return 0;
}
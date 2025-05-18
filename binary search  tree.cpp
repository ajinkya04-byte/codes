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
    
int isBst(struct node* root){
    static struct node* prev;
    if (root!=NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        
        if (prev!=NULL && root->data<=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBst(root->right);
    } else {
        return 1;
    }
}

struct node* search(struct node* root,int key){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==key)
    {
        return root;
    }
    else if (root->data>key)
    {
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

struct node* searchIter(struct node* root,int key){

    while (root!=NULL)
    {
    if (key==root->data)
    {
        return root;
    }
    else if (key <root->data)
    {
        root=root->left;
    }
    else
    {
        root=root->right;
    }
    }
    return NULL;
}

void insert(struct node* root,int key){
    struct node* prev=NULL;
    struct node* ptr;

    while(root!=NULL){
        if(key==root->data){
            return ;
        }
        else if (key<root->data)
        {
            prev=root->left;
        }
        else{
            prev=root->right;
        }
    }
    struct node* newNode=createNode(key);
    if(key<prev->data){
        root->left=newNode;
    }
    else{
        root->right=newNode;
    }
}

struct node* inOrderPredecessor(struct node* root){
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
    
}

struct node* del(struct node* root,int value){
    struct node* iPre;
    if (root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    
    if(value<root->data){
        root->left=del(root->left,value);
    }
    else if(value>root->data){
        root->right=del(root->right,value);
    }
    else{
        iPre=inOrderPredecessor(root);
        root->data=iPre->data; 
        root->left=del(root->left,iPre->data);
    }
    return root;
}

int main()
{
    
    struct node* n1=createNode(71);
    struct node* n2=createNode(72);
    struct node* n3=createNode(4);
    struct node* n4=createNode(41);
    struct node* n5=createNode(42);
    struct node* n6=createNode(73);
    

    

    n1->left=n4;
    n1->right=n2;
    
    n2->left=NULL;
    n2->right=n6;

    n4->left=n3;
    n4->right=n5;

    // cout<<isBst(n1)<<"\n";
    // struct node* p=searchIter(n1,41);
    // postorder(n);
    // cout<<p->data<<"\n";

    
    // inorder(n1);
    // cout<<"\n";
    del(n1,73);
    preorder(n1);


    
    return 0;
}
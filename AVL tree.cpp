#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

void preorder(struct node* root){
    
    if(root!=NULL){
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
    }
}

int max(int a,int b){
    return a>b?a:b;
}

int getHeight(struct node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct node* create(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;

    return n;
}

int getBalanceFactor(struct node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}



struct node* leftRotate(struct node* y){
    struct node* x=y->left;
    struct node* t2=x->right;
    x->right=y;
    y->left=t2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return x;

}

struct node* rightRotate(struct node* x){
    struct node* y=x->right;
    struct node* t2=y->left;

    x->right=t2;
    y->left=x;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return y;
}

struct node*  insert(struct node*n,int key){
    
        if(n==NULL){
            return (create(key)) ;
        }
        else if (key<n->data)
        {
            n->left=insert(n->left,key);
        }
        else{
            n->right=insert(n->right,key);
            return n;
        }

        n->height=1+max(getHeight(n->left),getHeight(n->right));
        int bf=getBalanceFactor(n);

        //left left
        if (bf>1 && key<n->left->data)
        {
            return rightRotate(n);
        }
        if (bf<1 && key>n->right->data)
        {
            return leftRotate(n);
        }
        if (bf>1 && key>n->left->data)
        {
            n->left=leftRotate(n->left);
            return rightRotate(n);
        }
        if (bf<1 && key<n->left->data)
        {
            n->right=rightRotate(n->right);
            return leftRotate(n);
        }
        return n;
        
}

int main()
{

    struct node* root=NULL;
    root=insert(root,67);
    root=insert(root,65);
    root=insert(root,66);
    root=insert(root,68);
    root=insert(root,50);
    root=insert(root,70);

    preorder(root);
    
    return 0;
}
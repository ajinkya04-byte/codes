#include <iostream>
using namespace std;

struct queue* f;
struct queue* r;

struct queue{
    int data;
    struct queue* next;
    struct queue* prev;
};

void EnqueueF(int data){
    struct queue* n=(struct queue*)malloc(sizeof(struct queue));
    if(f==NULL){
        f=r=n;
    }
    else{
        n->next=f;
        n->data=data;
        f->prev=n;
        f=n;
    }
}

void EnqueueR(int data){
    struct queue* n=(struct queue*)malloc(sizeof(struct queue));
    if(r==NULL){
        f=r=n;
    }
    else{
    r->next=n;
    n->prev=r;
    n->data=data;
    n->next=NULL;
    r=n;
    }

}

int DequeueF(){
    struct queue* ptr=f;
    int a=-1;

    if (f==r)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    
    if(f==NULL){
        r=NULL;
    }
    else{
        f=f->next;
        ptr->prev=NULL;
        a=ptr->data;
        free(ptr);
        cout<<"Deleted "<<a<<endl;
        return a;
    }
}

int DequeueR(){
    struct queue* ptr=f;
    int a=-1;

    if (f==r)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    
    if(r==NULL){
        f=NULL;
    }
    else{
        r=r->prev;
        r->next=NULL;
        
        a=ptr->data;
        free(ptr);
        cout<<"Deleted "<<a<<endl;
        return a;
    }
}


void display(struct queue *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    EnqueueR(7);
    EnqueueR(74);
    EnqueueR(76);
    EnqueueR(72);

    DequeueR();
    
    return 0;
}
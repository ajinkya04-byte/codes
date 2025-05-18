#include <iostream>
using namespace std;
    struct queue* f=NULL;
    struct queue* r=NULL;

struct queue{
    int data;
    struct queue* next;
};

void Enqueue(int data){
    struct queue* n=(struct queue*)malloc(sizeof(struct queue));

    if(n==NULL){
        cout<<"Queue is full "<<endl;
    }
    else{
        n->data=data;
        n->next=NULL;

        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int Dequeue(){
    
    
    struct queue* ptr=f;
    if(f==NULL){
        cout<<"Queue is empty "<<endl;
    }
    else{
        f=f->next;
        int a=-1;
        a=ptr->data;
        free(ptr);
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

    Enqueue(7);
    Enqueue(74);
    Enqueue(76);
    Enqueue(72);

    display(f);

    cout<<"After dequeue "<<endl;
    Dequeue();
    display(f);

    
    return 0;
}
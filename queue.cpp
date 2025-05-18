#include <iostream>
using namespace std;

struct queue {
    int size;
    int front;
    int back;
    int* arr;
};

void enqueue(struct queue* ptr,int data){
    if (ptr->back==ptr->size-1)
    {
        cout<<"Queue is full "<<endl;
    }
    else
    {
        ptr->back=ptr->back+1;
        ptr->arr[ptr->back]=data;
        
    } 
}

void dequeue(struct queue* ptr){
    if (ptr->front==ptr->back)
    {
        cout<<"Cannot dequeue empty queue "<<endl;
    }
    else
    {
        
        ptr->front++;
        ptr->arr[ptr->front-1]=ptr->arr[ptr->front];
        
        

    }  
}

void display(struct queue* q){
    for (int i = 0; i < q->size; i++)
    {
        cout<<"Queue is "<<q->arr[i]<<endl;
    }
    
}


int main()
{
    struct queue* q;
    
    q->size=5;
    q->back=-1;
    q->front=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    enqueue(q,7);
    enqueue(q,9);
    enqueue(q,4);
    enqueue(q,73);
    enqueue(q,72);
    cout<<"Before deletion "<<endl;
    display(q);

 
    cout<<"After deletion "<<endl;
    dequeue(q);
    display(q);


    return 0;
}
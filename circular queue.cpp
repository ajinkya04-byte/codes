#include <iostream>
using namespace std;

struct queue {
    int size;
    int front;
    int back;
    int* arr;
};
void enqueue(struct queue* ptr,int data){
    if ((ptr->back+1)%ptr->size==ptr->front)
    {
        cout<<"Queue is full "<<endl;
    }
    else
    {
        ptr->back=(ptr->back+1)%ptr->size;
        ptr->arr[ptr->back]=data;
        cout<<"EnQueue  "<<endl;
        
    } 
}

int dequeue(struct queue* ptr){
    if (ptr->back==ptr->front)
    {
        cout<<"Cannot dequeue empty queue "<<endl;
    }
    else
    {
        int a=-1;
        ptr->front=(ptr->front+1)%ptr->size;
        a=ptr->arr[ptr->front];
        cout<<"DeQueue  "<<endl;
        return a;
    }  
}


int main()
{
    struct queue* q;
    
    q->size=5;
    q->back=0;
    q->front=0;
    q->arr=(int*)malloc(q->size*sizeof(int));

    enqueue(q,7);
    enqueue(q,9);
    enqueue(q,4);
    enqueue(q,73);
    enqueue(q,72);
    cout<<"Before deletion "<<endl;
    

 
    cout<<"After deletion "<<endl;
    dequeue(q);
    return 0;
}
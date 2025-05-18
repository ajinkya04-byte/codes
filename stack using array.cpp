#include <iostream>
using namespace std;

struct stack{
    int size;
    int* arr;
    int top;
};

void push(struct stack* ptr,int data){
    if(ptr->top==ptr->size-1){
        cout<<"Stack overflow! "<<"Cannot add "<<data<<" to the stack"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
        cout<<"Added sucessfully "<<data<<endl;
    }
}

int pop(struct stack* ptr){
    if(ptr->top==-1){
        cout<<"Stack underflow! "<<"Cannot delete from empty stack "<<endl;
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        cout<<"Deleted "<<val<<endl;
        
       return 0; 
    }
}

int main()
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));

    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));

    push(s,7);
    push(s,4);
    push(s,25);
    push(s,8);
    push(s,9);
    
   

    pop(s);


    return 0;
}
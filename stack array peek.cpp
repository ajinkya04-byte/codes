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

int peek(struct stack* ptr,int i){
    int ind=ptr->top-i+1;
    if(ind<0){
        cout<<"Invalid operation "<<endl;
    }
    else{
        return ptr->arr[ind];
    }
}

int stackTop(struct stack* ptr){
    cout<<"Element at top is "<<ptr->arr[ptr->top]<<endl;
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack* ptr){
    cout<<"Element at bottom is "<<ptr->arr[0]<<endl;
    return ptr->arr[0];
}
int main()
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));

    s->size=7;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));

    push(s,7);
    push(s,4);
    push(s,25);
    push(s,8);
    push(s,9);
    push(s,95);
    push(s,92);
    
    
    // pop(s);
   
   

    // for (int i = 1; i <= s->top+1; i++)
    // {
    //     cout<<"The value at index "<<i<<" is "<<peek(s,i)<<endl;
    // }
    
    stackBottom(s);
    stackTop(s);
    
    return 0;
}
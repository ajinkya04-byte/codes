#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

void display(struct node* ptr) {
    while (ptr != NULL) {
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node* push(struct node* top, int data) {
    // Allocate memory for the new node
    struct node* p = new node;

    if (p == NULL) {
        cout << "Stack is overflow!" << endl;
    } else {
        p->data = data;  // Set the data
        p->next = top;   // Link the new node to the current top
        top = p;         // Update the top pointer
        
    }
    return top;
}

struct node* pop(struct node** top) {
    if (*top == NULL) {
        cout << "Stack is empty" << endl;
        return NULL;
    } else {
        struct node* temp = *top;  // Temporary pointer to hold the top node
        *top = (*top)->next;       // Update the top pointer
        
        delete temp;               // Free memory of the popped node
        return *top;
    }
}

int peek(int pos){
    struct node* top;
    struct node* ptr=top;

    for (int i = 0; i < pos-1 ; i++)
    {
        ptr=ptr->next;
    }

    if(ptr==NULL){
        ptr->data;
        return 0;
    }
    else{
        return -1;
    }
    
}

int main() {   
    struct node* top = NULL;  // Initialize the stack as empty

    // Push elements onto the stack
    top = push(top, 7);
    top = push(top, 25);
    top = push(top, 4);
    top = push(top, 8);
    top = push(top, 6);

    cout << "Stack contents after pushes:" << endl;
    display(top);

    // // Pop an element from the stack
    // top = pop(&top);

    // cout << "Stack contents after popping one element:" << endl;
    // display(top);

    for (int i = 0; i < 4; i++)
    {
        cout<<"Value at position "<<i<<" is"<<peek(i);
    }
    

    
    return 0;
}

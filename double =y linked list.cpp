#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node* head){
    struct node* ptr=head->next;
    cout<<"Element is: "<<head->data<<endl;
    

    while (ptr->prev!=NULL)
    {
        cout<<"Element is: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
    
}

struct node* insert_at_begining(struct node* head,int data){
    struct node* ptr=new struct node;
    ptr->data=data;
    ptr->next=head;

    if(head!=NULL){
    head->prev=ptr;
    }
    ptr->prev=NULL;
    head=ptr;
    
    return head;
}

int main()
{
    struct node *head=nullptr;
    struct node *second=nullptr;
    struct node *third=nullptr;
    struct node *fourth=nullptr;

    head = new struct node;
    second = new struct node;
    third = new struct node;
    fourth = new struct node;

    head->data = 7;
    head->next = second;
    head->prev=NULL;

    second->data = 54;
    second->next = third;
    second->prev=head;

    third->data = 25;
    third->next = fourth;
    third->prev=second;

    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev=third;

    display(head);

    head=insert_at_begining(head,5);

    display(head);

    return 0;
}
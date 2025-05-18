#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void display(struct node* head){
    struct node* ptr=head;
    do
    {
        cout<<"Element is "<<ptr->data<<endl;
        ptr=ptr->next;

    } while (ptr!=head);
    
}

struct node* insert_at_begining(struct node* head,int data){
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p=head->next;

    while (p->next!=head)
    {
        p=p->next;
    }
    
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;
    
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 25;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;
    
    display(head);

    cout<<"Insertion at begining "<<endl;
    head=insert_at_begining(head,8);
    display(head);

    return 0;
}
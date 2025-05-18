#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *insert_at_begining(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct node *insert_afteraNode(struct node *head,struct node* prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    ptr->data = data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

struct node *insert_in_between(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node *delete_at_begining(struct node *head){
    struct node *ptr=head;
    head=head->next;

    free(ptr);
    return head;
}

struct node *delete_in_between(struct node *head,int index){
    struct node *p=head;
    struct node *q=head->next;

    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
        
    }   
        p->next=q->next;
        free(q);

        return head;
}

struct node *delete_at_end(struct node *head){
    struct node *p=head;
    struct node *q=head->next;

    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        
    }   
        p->next=NULL;
        free(q);

        return head;
}

struct node *delete_at_value(struct node *head,int key){
    struct node *p=head;
    struct node *q=head->next;

    while( q->data!=key && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        
    }   
        p->next=q->next;

        free(q);

        return head;
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 25;
    third->next = NULL;

    display(head);


    // Insertion at begining:
    cout << "Insertion at begining: " << endl;
    head = insert_at_begining(head, 2);
    display(head);

    // Insertion in between:
    cout << "Insertion in between: " << endl;
    head = insert_in_between(head, 6, 3);
    display(head);

    // // Insert at end
    // cout << "Insertion at end: " << endl;
    // head = insert_at_end(head, 9);
    // display(head);

    // // Insert after a node
    // cout << "Insertion after a node: " << endl;
    // head = insert_afteraNode(head, third,1);
    // display(head);

    // Deletion at begining 
    cout<<"Deleting the first node: "<<endl;
    head=delete_at_begining(head);
    display(head);

    // Deletion in between
    cout<<"Deleting the node: "<<endl;
    head=delete_in_between(head,3);
    display(head);

    // // Deletion at end
    // cout<<"Deleting the last node: "<<endl;
    // head=delete_at_end(head);
    // display(head);

    // // Deletion at value
    // cout<<"Deleting the value node: "<<endl;
    // head=delete_at_value(head,1);
    // display(head);
    return 0;
}
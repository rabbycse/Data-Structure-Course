#include<stdio.h>
#include<stdlib.h>
typedef struct mylist
{
    int data;
    struct mylist *n;
    struct mylist *p;
}node;
int main()
{
    node *head=(node*)malloc(sizeof(node));
    node *mid=(node*)malloc(sizeof(node));
    node *tail=(node*)malloc(sizeof(node));

    head->data=4;
    mid->data=5;
    tail->data=6;

    head->n=mid;
    mid->n=tail;
    tail->n=head;

    head->p=tail;
    mid->p=head;
    tail->p=mid;

    printf("Circular Doubly List is: \n\n");

    node *temp=head;

    printf("%d->",temp->data);

    temp=temp->n;
    while(temp!=head)
    {
        printf("%d->",temp->data);
        temp=temp->n;
    }
     printf("%d->",temp->data);
     temp=temp->p;
    while(temp!=head)
    {
        printf("%d",temp->data);
        temp=temp->n;
    }
    return 0;

}


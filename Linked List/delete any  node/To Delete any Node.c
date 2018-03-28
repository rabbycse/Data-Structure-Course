#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*head;

void createList(int n);
void deletingnode(int b);
void displayList();

int main()
{
    int n,b;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter data for delete node:");
    scanf("%d",&b);
    deletingnode(b);
    displayList();
    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data of node %d: ", i);
            scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;
                temp = temp->next;
    }
}

void deletingnode(int b)
{
    int num=1;
    struct node *prevnode=NULL;
    struct node *currnode=head;
    while(currnode!=NULL && currnode->data!=b)
    {
        prevnode=currnode;
        currnode=currnode->next;
        num++;
    }
    if(currnode!=NULL)
    {
       prevnode->next=currnode->next;
       free(currnode);
    }
    else
    {
         head=currnode->next;
    }

}
void displayList()
{
    struct node *temp;
        temp = head;
        while(temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
}



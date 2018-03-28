#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;


void createList(int n);
void finding(int x);
void deleteFirstNode();
void displayList();



int main()
{
    int n, choice,x;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter the data to find: ");
    scanf("%d", &x);
    choice=find(x);
    printf("\n\nIt is in the index number = %d",x);

    printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    if(choice == 1)
    deleteFirstNode();

    printf("\nData in the list \n");
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

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

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

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
}

void deleteFirstNode()
{
    struct node *toDelete;

        toDelete = head;
        head = toDelete->next;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
}

int find(int x)
{
    struct node * crrNode=head;
    int index=1;
    while(crrNode!=NULL && crrNode->data!=x)
    {
        crrNode=crrNode->next;
        index++;
    }
    if(crrNode!=NULL)
    {
        return index;
    }
    else
        return 0;
}

void displayList()
{
    struct node *temp;

        temp = head;
        while(temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
}

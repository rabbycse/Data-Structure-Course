#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;


void createList(int n);
void insertNodeAtMiddle(int data, int position);
void finding(int x);
void displayList();


int main()
{
    int n, data, position,x;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter the data to find: ");
    scanf("%d", &x);
    data=find(x);
    printf("\n\nIt is in the index number = %d",x);

    printf("\nEnter data to insert at middle of the list: ");
    scanf("%d", &data);
    printf("Enter the position to insert new node: " );
    scanf("%d", &position);
    insertNodeAtMiddle(data, position);

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

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
}

void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;

        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

        }

        if(temp != NULL)
        {
            newNode->next = temp->next;

            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
}

void find(int x)
{
    struct node *currnode=head;
    int currindex=1;
    while(currnode!=NULL&&currnode->data!=x)
    {
        currnode=currnode->next;
        currindex++;
    }
    if(currnode!=NULL)
    {
        return currindex;
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

#include <stdio.h>
#include <conio.h>

struct node {
    int data;
    struct node *next;
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void finding(int x);
void displayList();


int main()
{
    int n, data,x;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter the data to find: ");
    scanf("%d", &x);
    data=find(x);
    printf("\n\nIt is in the index number  %d",x);

    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);

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

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head;

        head = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
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

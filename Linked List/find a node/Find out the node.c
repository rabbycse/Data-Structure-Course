#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head;
int main()
{
    int n, data,x,m;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    insert(n);

    printf("\nData in the list \n");
    print();
    printf("Enter the data to find: ");
    scanf("%d", &x);
    m=find(x);
    printf("\n\n%d  is in node no %d",x,m);

    return 0;
}
void insert(int n)
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
void print()
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

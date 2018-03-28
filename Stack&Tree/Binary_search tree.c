#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};
struct node* newNode( int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}

void Postorder(struct node* node)
{
     if (node == NULL)
        return;

     Postorder(node->left);
     Postorder(node->right);
     printf("%d ", node->data);
}

void Inorder(struct node* node)
{
     if (node == NULL)
          return;

     Inorder(node->left);
     printf("%d ", node->data);
     Inorder(node->right);
}

void Preorder(struct node* node)
{
     if (node == NULL)
          return;
     printf("%d ", node->data);
     Preorder(node->left);
     Preorder(node->right);
}

int main()
{
     struct node *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(6);
     root->right->right = newNode(7);

     printf("Traversing of Binary_Search Tree:\n");

     printf("Preorder:");
     Preorder(root);

     printf("\nInorder:");
     Inorder(root);

     printf("\nPostorder:");
     Postorder(root);

     return 0;
}

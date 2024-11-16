#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* newnode(int x)
{
   struct node* node;
   node=(struct node*)malloc(sizeof(struct node));
   node->data=x;
   node->right=NULL;
   node->left=NULL;
    return (node);
} 
// int  identical(struct node* a, struct node* b)
// {
//     if(a==NULL && b== NULL)
//         return 1;
//     else if(a!=NULL&& b!=NULL)
//     {
//         if(a->data == b->data)
//              return 1;
//     }
//     else
//           return 0;
//       identical(a->left, b->left);
//      identical(a->right, b->right);
// }

void postorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
void inOrder(struct node* root )
{
    
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    printf("%d",root->data);
    postorder(root->right);
}
void mirror(struct node* node)
{
    if (node == NULL)
        return  ;
    else {
        struct node* temp;
 
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
 
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
} 
int main()
{

    struct node* root1 = newnode(1);
    struct node* root2 = newnode(4);

    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left = newnode(4);
    root1->left->right = newnode(6);
 
    // root2->left = newnode(2);
    // root2->right = newnode(3);
    // root2->left->left = newnode(4);
    // root2->left->right = newnode(5);
    // int c=identical(root1, root2);
    // if (c==1)
    //     printf("Both tree are identical.");
    // else
    //     printf("Trees are not identical.");
   
    printf("Inorder traversal of the constructed"
           " tree is \n");
    inOrder(root1);
    mirror(root1);
 
    /* Print inorder traversal of the mirror tree */
    printf("\nInorder traversal of the mirror tree"
           " is \n");
    inOrder(root1);
 return 0;
}

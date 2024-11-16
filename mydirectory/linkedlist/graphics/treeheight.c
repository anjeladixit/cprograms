#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter data x");
    scanf("%d",&x);
    if(x==-1)
       {return 0;}
    
    newnode->data=x;
    printf("enter left elemnet of %d",x);
    newnode->left=createnode();
    printf("enter right  elemnet of %d",x);
    newnode->right=createnode();
    return newnode;
}
int max(struct node* root)
{
    struct node* current;
    current =root;
    if(current  ==NULL)
      return -1;
    
    while (current->right!=NULL)
    
        current=current->right;
    
    return current->data;

}
int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a == NULL && b == NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL) {
        return (a->data == b->data
                && identicalTrees(a->left, b->left)
                && identicalTrees(a->right, b->right));
    }
 
    /* 3. one empty, one not -> false */
    return 0;
}
void mirror(struct node* root)
{
   
    if(root==NULL)
      return;
    else{
         struct node* temp;
         mirror(root->left);
         mirror(root->right);
         temp=root->left;
         root->left=root->right;
         root->right=temp;

    }
}
void inorder(struct node * root)
{
    if(root==NULL)
      return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
bool ismirror(struct node*a,struct node* b)
{
   if(a==NULL && b==NULL)
   {
    return true;
   }
   if(a&&b&&a->data==b->data)
     return ismirror(a->left,b->right)&& ismirror(a->right,b->left);
   
   return false;

}
bool sym(struct node* root)
{
    return ismirror(root,root);
}
int height(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else{
        
        int lheight=height(root->left);
        int rheight=height(root->right);
     return 1+(lheight>rheight?(lheight-rheight):(rheight-lheight));
    }
}
int main()
{
    struct node* root1=createnode();
    //struct node* root2=createnode();
   // printf("max is %d",max(root1));
    //  if (identicalTrees(root1, root2))
    //     printf("Both tree are identical.");
    // else
    //     printf("Trees are not identical.");
    // printf("\n");
    //  printf("Inorder traversal of the constructed"
    //        " tree is \n");
    // inorder(root1);
 
    // /* Convert tree to its mirror */
    // mirror(root1);
 
    // /* Print inorder traversal of the mirror tree */
    // printf("\nInorder traversal of the mirror tree"
    //        " is \n");
    // inorder(root1);
//     if (sym(root1))
//         printf("Symmetric");
//     else
//         printf("Not symmetric");
//     return 0;
// }
//printf("%d",height(root1));
 if(height(root1)-1<=1)
   printf("balanced %d",height(root1));
else  
printf("not balanced");
}
#include<stdio.h>
#include<stdlib.h>
int c=0;
int sum=0;
struct node{
    int data;
    struct node* right;
    struct node* left;

};
struct node* createnode()
{
    int x;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&x);
    if(x==-1)
       {return 0;}
       newnode->data=x;
       printf("enter right  child %d",x);
       newnode->right=createnode();
       printf("enter left child %d",x);
       newnode->left=createnode();
       return newnode;
}
void postorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    c++;
    sum=sum+root->data;
    
  

}
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    printf("%d",root->data);
    c++;
    postorder(root->left);
    postorder(root->right);
    

}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    printf("%d",root->data);
    c++;
    postorder(root->right);
}
// int count(struct node* root)
// {
//     if(root !=NULL)
//     {
//         return 1+count(root->left)+count(root->right);
//     }
// }
int height(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    
    }
    else
    {
    int lheight=height(root->left);
    int  rheight=height(root->right);
    return 1+(lheight>rheight?lheight:rheight);
    }
}
int  main()
{
    struct node* root;
    root=createnode();
    postorder(root);
    printf("\n");
    printf(" number of nodes are %d\n",c);
     printf(" sum of nodes are %d\n",sum);
    printf(" height  of nodes are %d\n",height(root));
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    

}
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
int height (struct node* root)
{
    if(root==NULL)
    {
        return 0;
    
    }
    else
    {
    int lheight=height(root->left);
    int  rheight=height(root->right);
    return 1+(lheight+rheight);
    }
}

int  main()
{
     int leafCount = 0, nonLeafCount = 0;
    struct node* root;
    root=createnode();
    printf(" height  of nodes are %d\n",height (root)-1);

}
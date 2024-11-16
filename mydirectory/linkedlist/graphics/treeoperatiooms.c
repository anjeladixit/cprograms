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
int leftchild(struct node *root)
{
    if(root)
    {
        if(root->left!=NULL)
        {
            return(1+leftchild(root->left)+leftchild(root->right));
        }
        else
        {
            return(0+leftchild(root->left)+leftchild(root->right));
        }
    }
    else
    return 0;
}
void countNodes(struct node* root, int* leafCount, int* nonLeafCount) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) // Leaf node
        (*leafCount)++;
    else // Non-leaf node
        (*nonLeafCount)++;

    // Recursively count in left and right subtrees
    countNodes(root->left, leafCount, nonLeafCount);
    countNodes(root->right, leafCount, nonLeafCount);
}

int singlechild(struct node *root)
{
    if (root==NULL)
    return 0;
   
    else if((root->left==NULL && root->right!=NULL) ||(root->right==NULL && root->left!=NULL))
    {
        return 1+
        singlechild(root->left)+
        singlechild(root->right);
    }
    else 
    {
        return (singlechild(root->left)+singlechild(root->right));
    }
    //  if (root == NULL)
    //     return 0;
    // else if (root->left == NULL && root->right == NULL) // leaf node
    //     return 0;
    // else if(root->left!=NULL)
    //    return 1 +
    // else if(root->right!=NULL)
    //    return 1;
    // else
    //     return szinglechild(root->left) + singlechild(root->right);
}

int leaf(struct node* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
       return  leaf(root->left)+leaf(root->right);
    }
}
void degree(struct node *root)
{
    int d;
    if(root==NULL)
    {
        return;
    }
    else if(root->left==NULL&& root->right==NULL)
    {
        d=0;
    }
    else if(root->left!=NULL&& root->right!=NULL)
    {
        d=2;
    }
    else 
      d=1;
    printf("%d degre is %d   ",root->data,d);
    degree(root->left);
    degree(root->right);

}
int findMin(struct node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; 
    }

    struct node* current = root;

    // Keep going left until the leftmost node is reached
    while (current->left != NULL)
        current = current->left;

    return current->data;
}

int  main()
{
     int leafCount = 0, nonLeafCount = 0;
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
    printf("\n");
    // printf("no. of leaf nodes %d",leaf(root));
    // printf("\n");
    //  printf("no. of left nodes %d",leftchild(root));
    // printf("\n");
    // printf("no. of single child  nodes %d",singlechild(root));
    // printf("\n");
    // degree(root);
    printf("\n");
     countNodes(root, &leafCount, &nonLeafCount);
      printf("Number of leaf nodes: %d\n", leafCount);
    printf("Number of non-leaf nodes: %d\n", nonLeafCount);
   printf("/n");
    int minElement = findMin(root);
    if (minElement != -1)
        printf("The minimum element in the BST is: %d\n", minElement);


}
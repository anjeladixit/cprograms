#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        root=createnode(data);
        return root;
    }
    else if(data<root->data){
        {
            root->left=insert(root->left,data);
        }
    }
     else if(data>root->data){
        {
            root->right=insert(root->right,data);

        }


     }
     return root;
}
void inorder(struct node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}
int height(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else 
    {
        int left_height=height(root->left);
        int right_height=height(root->right);
        if(left_height>right_height)
        {
            return left_height+1;
        }
        else
        {
            return right_height+1;
        }

    
    }
}
int main()

{
     struct node* root = NULL;  // Initialize root to NULL
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 34);
    root = insert(root, 110);

    printf("%d" ,height(root));
    printf("\n");
    inorder(root);

}
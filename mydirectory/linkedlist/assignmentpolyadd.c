#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node* next;
};
struct node* insert(struct node*head,int co,int ex)
{
    struct node* temp;
    struct node* newp=malloc(sizeof(struct node));
    newp->coeff=co;
    newp->expo=ex;
    newp->next=NULL;
    if(head==NULL || ex>head->expo)
    {
        newp->next=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->next !=NULL && temp->next->expo>ex)
        {
            temp=temp->next;
        }
        newp->next=temp->next;
        temp->next=newp;
    }
    return head;
}
struct node* create(struct node* head)
{
    int n;
    int coeff;
    int expo;
    printf("enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter coeff of %d",i+1);
        scanf("%d",&coeff);
        printf("enter expo of %d",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}

void print(struct node* head)
{

    if(head==NULL)
       printf("no");
    else
    {
        struct node* temp= head;
        while(temp !=NULL)
        {
            printf("%dx^%d",temp->coeff,temp->expo);
            temp=temp->next;
            if(temp !=NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }

        }

    }
}

void polyadd(struct node* head1,struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;

        }
        else if(ptr1->expo>ptr2->expo)
        {
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;

        }
        else if(ptr1->expo<ptr2->expo)
        {
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;

        }
    }
    while(ptr1!=NULL)
    {
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
     while(ptr2!=NULL)
    {
        head3=insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->next;
    }
    printf("afdded");
    print(head3);
}
int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    printf("enter 1 poluy");
    head1=create(head1);
     printf("enter 2 poluy");
    head2=create(head2);
    polyadd(head1,head2);


}
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

struct node* polyadd(struct node* head1, int* a, int n2) {
    for (int i = 0; i <= n2; i++) {
        if (a[i] != 0) {
            head1 = insert(head1, a[i], i);
        }
    }
    struct node* temp=NULL;
    struct node* ptr=head1;
    while(ptr->next!=NULL)
    {
        if(ptr->expo==ptr->next->expo)
        {
            ptr->coeff=ptr->coeff+ptr->next->coeff;
            temp=ptr->next;
            ptr->next=ptr->next->next;
            free(temp);
            temp=NULL;
        }
        else{
            ptr=ptr->next;
        }
    }
    return head1;
}

int main()
{
    struct node* head1=NULL;
    printf("enter 1 poluy");
    head1=create(head1);
    int n2;
    printf(" highest terms for poly 2");
    scanf("%d",&n2);
    int a[n2+1];
    int i;
    for(int i=0;i<=n2;i++)
    {
        printf("coeff for  %d power",i);
        scanf("%d",&a[i]);

    }


   head1=polyadd(head1,a,n2);
    print( head1);




}
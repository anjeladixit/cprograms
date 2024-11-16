#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node* next;
};
struct node *insert(struct node* head,int co,int ex)
{
    struct node* temp;
    struct node* newp=malloc(sizeof(struct node));
    newp->coeff=co;
    newp->expo=ex;
    if(head==NULL )
    {
        head=newp;
        head->next=head;
    }
    else 
    {
        temp=head;
        while(temp->next  !=head)
                temp=temp->next;
        // newp->next=temp->next;
         temp->next=newp;
         newp->next=head;
    }
    return head;

}
struct node*create(struct node* head)
{
        int n;
        int coeff;
        int expo;
        printf("no. of terms");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            printf("coefficient of %d",i+1);
            scanf("%d",&coeff);
             printf("expo of %d",i+1);
            scanf("%d",&expo);
            head=insert(head,coeff,expo);
        }
        return head;
 }
void print(struct node* head)
    {

        if(head==NULL)
         { printf("no");
        return;}
        struct node* temp=head;
       do {
        printf("(%dx^%d)", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    } while (temp != head);
    printf("\n");
}
 struct node* removeeven(struct node* head1)
    {  

        struct node* ptr1=head1;
        struct node* head3=NULL;
        if (head1 == NULL) {
        return NULL;
    }
       do{
        {
            if(ptr1->expo%2==0)
            {      struct node* temp=head1;
               if(ptr1==head1)
               {
           
                 while(temp->next!=head1)
                 {
                    temp=temp->next;
                 }
               
                 head1=head1->next;
                 temp->next=head1;
                 free(ptr1);
                 ptr1=head1;
                 if(temp==ptr1)
                 {
                    head1=NULL;
                   break;
                 }
               }
                    
               else{
                struct node* temp=head1;
                 while(temp->next!=ptr1)
                 {
                    temp=temp->next;
                 }
                 temp->next=ptr1->next;
                 free(ptr1);
                 ptr1=temp->next;
               }
            }
           else{
                struct node* temp=ptr1;
                ptr1=ptr1->next;

            }
            
    
       }  
    return head1;
 }while(ptr1!=head1 );
   
 }
int main()
{
    struct node* head1=NULL;

    printf("enter first polunomial");
    head1=create(head1);

    head1=removeeven(head1);

    print(head1);



}
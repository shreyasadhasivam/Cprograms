#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void display(struct node *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are\n");
    while(first != NULL)
    {
        printf("%d ",first->data);
     first = first->link;
    }
    printf("\n");
}
struct node *insertRear(int ele,struct node *first)
{
   struct node *ptr;
   ptr = (struct node *)malloc(sizeof(struct node *));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->link = NULL;
    return ptr;
   }
   struct node *temp = first;
   while(temp->link != NULL)
   {
    temp = temp->link;
   }
   temp->link = ptr;
   ptr->link = NULL;
   return first;
}
struct node *cubelist(struct node *head,struct node *head1,struct node *head2,int n)
{
    int temp;
   struct node *ptr = head;
   while(ptr != NULL){
   if(ptr->data % 2 == 0)
   {
     temp = ptr->data*ptr->data*ptr->data;
     head2 = insertRear(temp,head2);
     ptr = ptr->link;
   }
   else{
    temp = ptr->data*ptr->data*ptr->data;
     head1 = insertRear(temp,head1);
     ptr = ptr->link;
   }
   }
     if(n==0)
     {
        return head1;
     }
     else
     {
        return head2;
     }
   }
int main()
{
    struct node *head;
    struct node *head1;
    struct node *head2;
    head = (struct node *)malloc(sizeof(struct node *));
    head1 = (struct node *)malloc(sizeof(struct node *));
    head2 = (struct node *)malloc(sizeof(struct node *));
    printf("Enter number of elements \n");
    head = NULL;
    head1=NULL;
    head2=NULL;
    int n1,n2,t;
    scanf("%d",&n1);
    printf("Enter elements \n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&t);
        head = insertRear(t,head);
    }
    display(head);
    printf("Odd list after cubing: \n");
    head1 = cubelist(head,head1,head2,0);
    display(head1);
    head2 = cubelist(head,head1,head2,1);
    printf("Even list after cubing: \n");
    display(head2);
    return 0;
}
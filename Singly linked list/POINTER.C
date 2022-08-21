#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_first();
void print_list();
void insert_last();
void insert_middle();
void dlt_first();
void dlt_last();
void dlt_mid();
struct node
{
int value;
struct node *next;
}*head=NULL;
void main()
{
int ch,i=0;
clrscr();
printf("Choices:\n1.Insert first\t 2.Insert last \t3.Insert middle \n4.Delete first \t5.Delete last \t6.Delete particular ");
while(1)
{
printf("\nEnter a choice:");
scanf("%d",&ch);
i++;
switch(ch)
{
case 1:
   insert_first();
   print_list();
   break;
case 2:
   insert_last();
   print_list();
   break;
case 3:
   insert_middle();
   print_list();
   break;
case 4:
   dlt_first();
   print_list();
   break;
case 5:
   dlt_last();
   print_list();
   break;
case 6:
   dlt_mid();
   print_list();
   break;
default:
   printf("Wrong choice");
}
if(i==20)
 break;
}
}
void insert_first(int data)
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter a data to be added:");
scanf("%d",&data);
newnode->value=data;
newnode->next=NULL;
if(head==NULL)
 head=newnode;
else
{
 newnode->next=head;
 head=newnode;
}
}
void print_list()
{
struct node*ptr=head;
printf("n[head]=>" );
while(ptr!=NULL)
{
printf("%d=>",ptr->value);
ptr=ptr->next;
}
printf("[null]n");
}
void insert_last(int data)
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter a data to be added:");
scanf("%d",&data);
newnode->value=data;
newnode->next=NULL;
if(head==NULL)
head=newnode;
else
{
struct node *p=head;
while(p->next!=NULL)
 p=p->next;
p->next=newnode;
}
}
void insert_middle(int data)
{
int temp;
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data to be added:");
scanf("%d",&data);
newnode->value=data;
newnode->next=NULL;
if(head==NULL)
 head=newnode;
else
{
struct node *p=head;
printf("\nEnter a value after which data should placed :");
scanf("%d",&temp);
while(p->value!=temp)
 p=p->next;
newnode->next=p->next;
p->next=newnode;
}
}
void dlt_first()
{
if(head==NULL)
 printf("No list exist");
else
{
struct node*temp=head;
head=temp->next;
free(temp);
}
}
void dlt_last()
{
struct node*p,*temp;
if(head==NULL)
 printf("No list exists\n");
else
{
p=head;
if(p->next==NULL)
{
 head=NULL;
 free(p);
}
else
{
while(p->next->next!=NULL)
 p=p->next;
temp=p->next;
p->next=NULL;
free(temp);
}
}
}
void dlt_mid()
{
int data;
struct node *p,*temp;
if(head==NULL)
 printf("No list exists");
else
{
printf("Enter a value to be deleted:");
scanf("%d",&data);
p=head;
if(p->next==NULL)
{
 head=NULL;
 free(p);
 }
else
{
while(p->next->value!=data)
 p=p->next;
temp=p->next;
p->next=temp->next;
free(temp);
}
}
}




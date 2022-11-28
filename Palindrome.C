#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
node *head = NULL, *chead = NULL, *dummy;
void insert_last()
{
int data;
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
void traverse(node *ptr)
{
    node *temp = ptr;
    while (temp != NULL)
    {
	printf(" #%d# ", temp->value);
	temp = temp->next;
    }
}
void reversal()
{
    node *temp;
    // To find chead
    temp = head;
    while (temp->next != NULL)
    {
	temp = temp->next;
    }
    chead = temp;
    dummy = chead;
    while (1)
    {
	temp = head;
	while (temp->next != chead)
	    temp = temp->next;
	chead->next = temp;
	chead = chead->next;
	if (chead == head)
	    break;
    }
    chead->next = NULL;
}
int check()
{
struct node*p,*p1;
p=head;
p1=dummy;
while(p!=NULL&&p1!=NULL)
{
if(p->value==p1->value)
{
 p=p->next;
}
else
 printf("Not a palindrome");
 break;
}
if(p==NULL)
 printf("Palindrome:");
}
int main()
{
    int ch,i=0;
printf("Choices:\n1.Insert first\t 2.check palindrome");
while(1)
{
printf("\nEnter a choice:");
scanf("%d",&ch);
i++;
switch(ch)
{
case 1:
   insert_last();
   traverse(head);
   break;
case 2:
    reversal();
    traverse(dummy);
    check();
    break;
default:
 break;
}
}
}

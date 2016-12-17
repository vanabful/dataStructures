/*Make a program that generates 20 random numbers from 100 – 150 and saves them in linked list and
each of them gives a number from 0-19.
a) After that generate five random numbers from 0-19 (all numbers must be different)
and elements from previous list with that number have to go on top of the list. Print numbers in the new list. */

#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


struct _node;
typedef struct _node* position;
typedef struct _node
{
	int number;
	int element;
	position next;
}Node;

void enterInList(position);
position makeNewElement(position);
void insertAtTheTopOfList(position,int); //sets an element with specific number on top
void generateNumbers(position);
void printList(position);

int main()
{
	Node head;
	head.next=NULL;
	enterInList(&head);
	printf("FIRST LIST:\n");
	printList(head.next);
	generateNumbers(&head);
	printf("SECOND LIST:\n");
	printList(head.next);
	return 0;
}

void enterInList(position p) //prima head
{
	position q;
	int result;
	int counter=0;
	while(counter<20)
	{
	result = (rand()%(50))+100;
	printf("result: %d\n",result);
	q=makeNewElement(p);
	p=p->next;
	q->number=counter;
	q->element=result;
	counter++;
	}
}
position makeNewElement(position p) //gets last element
{
	position q;
	q=(position)malloc(sizeof(Node));
	if(q==NULL) return NULL;
	q->next=p->next;
	p->next=q;
	return q;
}
void insertAtTheTopOfList(position p,int rElement) //rElement is the element we position at the top
{
	position head;
	position prev;
	position temp;
	head=p;
	while((p->next!=NULL) && (p->next->number!=rElement))
	{
		p=p->next;
	}
	if(p->next==NULL)
	{
		printf("Error\n");
		return;
	}
	printf("element with this number is: %d\n",p->next->element);
	prev=p;
	temp=p->next;
	//merge
	prev->next=temp->next;
	temp->next=head->next;
	head->next=temp;
}
void generateNumbers(position p) //gets head
{
	int counter=0;
	int result[5];
	int temp;
	printf("\GENERATE 5 NUMBER FROM 0 TO 20 \n");
	srand ( time(NULL) );
	while(counter<5)
	{
		temp = rand() % 20;
		result[counter]=temp;
		for(int i=0;i<counter;i++)
		{
			if(result[i]==temp)
			{
				temp = rand() % 20;
				result[counter]=temp;
				i=0;
			}
		}
			printf("generated number is: %d\n",temp);
			insertAtTheTopOfList(p,temp); //sends head i number
			counter++;
	}
}
void printList(position p) //gets first element 
{
	while(p!=NULL)
	{
		printf("%d %d\n",p->number,p->element);
		p=p->next;
	}
}
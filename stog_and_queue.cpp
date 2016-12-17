#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef struct _stog* Position;
typedef struct _stog
{
	int x;
	Position next;
}Stog;

void PushStog(Position,int);
void PushQueue(Position,int);
void Pop(Position);
void Print(Position);
void PrintMenu();


int main(void)
{
  Stog head;
  Stog headR;
  int odluka,x;
  head.next=NULL;
  headR.next=NULL;
  PrintMenu();
  do
  {
    printf("Make a choice");
	scanf("%d",&odluka);

	switch(odluka)
	{
	 case 1: printf("Which element you want to add?");
		     scanf("%d",&x);
		     PushStog(&head,x);
			 break;
	 case 2: printf("Which element you want to add?");
		     scanf("%d",&x);
		     PushQueue(&headR,x);
			 break;
	 case 3: Pop(&head);
		     break;
	 case 4: Pop(&headR);
		     break;
	 case 5: Print(head.next);
		     break;
	 case 6: Print(headR.next);
		     break;
	 case 7: printf("End!\n");
		     break;
	}
  }while(odluka!=7);

  return 0;
}

void PushStog(Position p, int x)
{
  Position q=(Position)malloc(sizeof(Stog));
  q->x=x;
  q->next=p->next;
  p->next=q;
}

void Pop(Position p)
{
  Position temp;
  temp=p->next;
  p->next=temp->next;
  printf("Eliminated element is %d\n",temp->x);
  free(temp);
}

void Print(Position p)
{
  while(p!=NULL)
  {
	  printf("%d\n",p->x);
	  p=p->next;
  }
}

void PrintMenu()
{
  printf("**********MENU**********\n");
  printf("* 1.Push stog          *\n");
  printf("* 2.Push queue         *\n");
  printf("* 3.Pop stog           *\n");
  printf("* 4.Pop queue          *\n");
  printf("* 5.Print stog         *\n");
  printf("* 6.Print queue        *\n");
  printf("* 7.End                *\n");
  printf("************************\n");
}

void PushQueue(Position p, int x)
{
  Position q=(Position)malloc(sizeof(Stog));
  while(p->next!=NULL)
	  p=p->next;
  q->x=x;
  p->next=q;
  q->next=NULL;
  
}
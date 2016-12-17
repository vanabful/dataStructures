#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _student* Position;
typedef struct _city* Pos;
typedef struct _student
{
   int rbr;
   char name[20]; 
   char surname[20]; 
   char oib[12];
   Position next;
}Student;

typedef struct _city
{
  char oib[12];
  char city_name[50];
  int year;
  Pos next;
}City;

void ReadFromFileStudent(Position,char*);
void ReadFromFileMjesto(Pos,char*);
void Print(Position,Pos);
void PrintStudent(Position,Pos);

int main(void)
{
  char fileNameS[50],fileNameM[50];
  Student headS;
  headS.next=NULL;
  City headM;
  headM.next=NULL;
  printf("From which file you want to load students? Hint: students.txt");
  scanf("%s",fileNameS);
  ReadFromFileStudent(&headS,fileNameS);
  printf("From which file you want to load citys? Hint: city.txt");
  scanf("%s",fileNameM);
  ReadFromFileMjesto(&headM,fileNameM);

  printf("Student in city:");
  Print(headS.next,headM.next);

  printf("Studenti who don't live in Split:\n");
  PrintStudent(headS.next,headM.next);

  return 0;
}
void ReadFromFileStudent(Position p, char* fileName)
{
  FILE* fp;
  fp=fopen(fileName,"r");
  if(fp==NULL)
	  printf("Error!\n");
  while(!feof(fp))
  {
	  Position q=(Position)malloc(sizeof(Student));
	  fscanf(fp, "%d %s %s %s",&q->rbr, q->name,q->surname,q->oib);

	  q->next=p->next;
	  p->next=q;
	 
	  p=p->next;
  }
  
  fclose(fp);
}

void ReadFromFileCity(Pos p,char* fileName)
{
  FILE* fp;
  fp=fopen(fileName,"r");
  if(fp==NULL)
	  printf("Error!\n");
  while(!feof(fp))
  {
	  Pos q=(Pos)malloc(sizeof(City));
	  fscanf(fp,"%s %s %d",q->oib,q->city_name,&q->year);
	  q->next=p->next;
	  p->next=q;
	  p=p->next;
  }
  fclose(fp);
}

void Print(Position p,Pos q)
{
	Position temp;
	temp=p;
	printf("Checking\n");
	while(p!=NULL && q!=NULL)
	{
	  if(strcmp(p->oib,q->oib))
		p=p->next;
	  else
	  {
		  printf("Student %s u mjestu %s\n",p->name,q->city_name);
		  q=q->next;
		  p=temp;
	  }
	  
	}
	
}

void PrintStudent(Position p,Pos q)
{
  Position temp;
  temp=p;
  while(q!=NULL && p!=NULL)
  {
	  if(strcmp(q->city_name,"Split"))
	  {
	   if(strcmp(p->oib,q->oib))
		p=p->next;
	  else
	  {
		  printf("%s-%s-%s-%d\n",p->name,p->surname,q->city_name,q->year);
		  q=q->next;
		  p=temp;
	  } 
	  }
	  else
		  q=q->next;
  }
}

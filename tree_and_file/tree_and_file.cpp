/* Get a string from text file and order words in that string in a tree by their length. If two words are the same length, 
get their first character, and the one that has a higher ASCII number is bigger. */

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _Node *Position;
typedef struct _Node
{
	char content[100];
	Position left;
	Position right;
} Node;

Position AddElement(Position,char*);
Position CreateNode(char*);
void ReadFromFile(Position,char*);
void PrintInOrder(Position);

int main(void)
{
  Position root;
  root=NULL;
  char fileName[50];
  printf("Enter name of file(Hint:text.txt):");
  scanf("%s",fileName);

  ReadFromFile(root,fileName);
  

  return 0;
}
void ReadFromFile(Position p, char* fileName)
{
  FILE* fp;
  char text[100];
  int n,i;
  fp=fopen(fileName,"r");
  if(fp==NULL)
	  printf("Error!\n");
  while(!feof(fp))
  {
	  fscanf(fp,"%s",text);
	  n=strlen(text);
	  p=AddElement(p,text);
  }
  fclose(fp);
  PrintInOrder(p);
}

Position AddElement(Position p, char* text)
{
  int n,i;
  n=strlen(text);
  if(p==NULL)
	  p=CreateNode(text);
  else if(strlen(p->content)<n)
	  p->right=AddElement(p->right,text);
  else if(strlen(p->content)>n)
	  p->left=AddElement(p->left,text);
  else if(strlen(p->content)==n)
  {
	  for(i=0;i<strlen(text);i++)
	  {
	  if(p->content[i]>text[i])
		  p->right=AddElement(p->right,text);
	  else if(p->content[i]<text[i])
		  p->left=AddElement(p->left,text);
	  else if(!strcmp(p->content,text))
			  break;
	  }
  }
  return p;
}

Position CreateNode(char* text)
{
 Position q=(Position)malloc(sizeof(Node));
 if(q!=NULL)
 {
	 strcpy(q->content,text);
	 q->left=NULL;
	 q->right=NULL;
 }
 return q;
}

void PrintInOrder(Position p)
{
	int i;
	if(p==NULL) return;
	PrintInOrder(p->left);
	for(i=0;i<strlen(p->content);i++)
	{
		if(p->content[i]=='.' || p->content[i]==',')
			p->content[i]=' ';
	}
	printf("%s ",p->content);
	PrintInOrder(p->right);
}
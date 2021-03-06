#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word{
	char string[20];
	struct word *after;           //after points to the next node of structure word
	};
struct node{
	char alpha;
	struct word *link;            //link pointer holds the address of structure word
	struct node *next;            //next pointer holds the address of structure node
	};
void insertion();                  //to insert a word in dict
void deletion();                    //to delete a word from dict
void printone();                 //to print all words of given charater in dict
void count();			 //to count no.of entries of given character in dict
void printdict();              //to print entire dict
int dupstring(char[],char[]);     //function to compare strings without case sensitive
int cmpstring(char[],char[]);     //function to compare strings without case sensitive
void *insertword(struct node*, char[]);
struct node *head, *temp,*start, *t;
struct word *temp1,*m,*temp2,*str;
char r[20],swap[20];
void main(){
	int i,ch,v;
	char letter;
	for(i=0;i<=26; i++)
		{
		letter='A'+i;
		t=(struct node*)malloc(sizeof(struct node));
		t->alpha=letter;
		if(head==NULL)
			{
			head=t;
			t->link=NULL;
			}
		else
			{
			temp=head;
			while(temp->next)
				{
				temp=temp->next;
				}
			temp->next=t;
			t->link=NULL;
			}
		}
	printf("*******************************************************\n");
	printf("1 for insert new word\n2 for delete word\n3 for print all words of given letter\n4 for count all entries in given character\n5 for print entire dictionary\n6 for exit\n");
	printf("*******************************************************\n");
	printf("Enter non zero value to run the program:");
	scanf("%d",&v);
	while(v)
		{
		printf("Enter user choice from 1 to 6:");
		scanf("%d",&ch);
		switch(ch)
			{
			case 1:
				insertion();
				break;
			case 2:
				deletion();
				break;
			case 3:
				printone();
				break;
			case 4:
				count();
				break;
			case 5:
				printdict();
				break;
			case 6:
				exit(0);
			default:
				printf("Enter choice between 1-6");
			}
		printf("Enter non zero value to run the program:");
		scanf("%d",&v);
		}
}
void insertion()
	{
	printf("Enter string to insert:");
	scanf("%s",r);
	temp=head;
	int flag1=0;
	while(temp)
		{
		if(temp->alpha==r[0]||temp->alpha==r[0]-32)
			{
			m=(struct word*)malloc(sizeof(struct word));     // m holds new node address
			strcpy(m->string,r);
			m->after=NULL;
			temp1=temp->link;
			while(temp1)
				{
				if(dupstring(temp1->string,r)==0)
					{
					flag1=1;
					break;
					}
				temp1=temp1->after;
				}
			if(flag1==1)
				printf("Given word is already  present in dictionary\n");
			else
			{
			if(temp->link==NULL)
				{
				temp->link=m;
				}	
			else
				{
				temp1=temp->link;
				while(temp1->after)
					{
					temp1=temp1->after;
					}
				temp1->after=m;
				}
		temp1=temp->link;
		while(temp1->after)
			{
			temp2=temp1->after;
			while(temp2)
				{
				if(cmpstring(temp1->string,temp2->string)>0)
					{
					strcpy(swap,temp1->string);
					strcpy(temp1->string,temp2->string);
					strcpy(temp2->string,swap);
					}
				temp2=temp2->after;
				}
			temp1=temp1->after;
			}
		}
	}
		temp=temp->next;
		}
	}
void deletion()
	{
	int search=0;
	struct word *value;
	printf("Enter string to delete:");
	scanf("%s",r);
	temp=head;
	while(temp)
		{
		if(temp->alpha==r[0]||temp->alpha==r[0]-32)
			{
			temp1=temp->link;
			while(temp1)
				{
				if(dupstring(temp1->string,r)==0)
					{
					search=1;
					break;
					}
				temp1=temp1->after;
				}
			if(search==1)
			{
			temp1=temp->link;
			while(temp1 && dupstring(temp1->string,r)!=0)
				{
				value=temp1;
				temp1=temp1->after;
				}
			if (temp1==temp->link)
				{
				temp->link=temp1->after;
				free(temp1);
				}
			else
				{
				value->after=temp1->after;
				free(temp1);
				}
			}
			else
			printf("Dictionary has no given string\n");
			}
		temp=temp->next;
	}
}
void printone()
	{
	char d;
	printf("Enter letter to print all words of that:");
	scanf("\r%c",&d);
	temp=head;
	while(temp)
		{
		if(temp->alpha==d||temp->alpha==d-32)
			{
			temp1=temp->link;
			if(temp1==NULL)
				printf("There is no words belongs to given character\n");
			else
			{
			printf("|%c|----->",d);
			while(temp1)
				{
				printf("|%s|->",temp1->string);
				temp1=temp1->after;
				}
			}
		}
		temp=temp->next;
		}
		printf("\n");
	}
void count()
	{
	int c=0;
	char d;
	printf("Enter letter to count no. of entries of that:");
	scanf("\r%c",&d);
	temp=head;
	while(temp)
		{
		if(temp->alpha==d||temp->alpha==d-32)
			{
			temp1=temp->link;
			while(temp1)
				{
				c=c+1;
				temp1=temp1->after;
				}
			}
		temp=temp->next;
		}
	printf("Count of entries is:%d\n",c);
	}
void printdict()
	{
	int c=0;
	temp=head;
	while(temp)
		{
		if(temp->link!=NULL)
			{
			printf("|%c|---->",temp->alpha);
			temp1=temp->link;
			while(temp1)
				{
				c=c+1;
				printf("|%s|->",temp1->string);
				temp1=temp1->after;
				}
			printf("\n");
			}
		temp=temp->next;
		}
	if(c==0)
		printf("Dictionary is empty\n");
	}
int dupstring(char a[],char b[])
	{
	int i;
	int flag=0;
	for (i=0;i<strlen(a)||i<strlen(b);i++)
		{
		if(a[i]!=b[i]-32&&a[i]!=b[i]&&a[i]!=b[i]+32)
			{
			flag=1;
			break;
			}
		}
	return flag;
	}
int cmpstring(char a[],char b[])
	{
	int i;
	int flag=0;
	for (i=0;i<strlen(a)||i<strlen(b);i++)
		{
		if(a[i]!=b[i]+32&&a[i]>b[i])
			{
			flag=1;
			break;
			}
		else if(b[i]!=a[i]+32&&b[i]>a[i])
			{
			flag=0;
			break;
			}
		}
	return flag;
	}

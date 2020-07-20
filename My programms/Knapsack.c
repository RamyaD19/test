#include <stdio.h>
#include <stdlib.h>
typedef struct mdr{
	char item;
	int weight;
	int profit;
	float ratio;
	struct mdr *next;
	}node;
node *head,*temp,*t,*temp1,*temp2;
void main(){
	int ch,flag2,flag3,capacity1,capacity2,capacity,i=0,j=0,maxprofit1=0,len1=0,len2=0;
	float f,flag4,maxprofit2=0;
	char flag1,knapsack1[10],knapsack2[10];
	printf("Enter capacity of knapsack:");
	scanf("%d",&capacity);
	printf("0 for stop create node\n1 for create node\n");
	printf("Enter choice:");
	scanf("%d",&ch);
	while(ch)
	{
		t=(node*)malloc(sizeof(node));
		t->next=NULL;
		printf("Enter item:");
		scanf(" %c",&t->item);
		printf("Enter weight and profit:");
		scanf("%d%d",&t->weight,&t->profit);
		f=(float)t->profit/t->weight;
		t->ratio=f;
		if(head==NULL)
			head=t;
		else
		{
			temp=head;
			while(temp->next)
				temp=temp->next;
			temp->next=t;
		}
		printf("Enter choice:");
		scanf("%d",&ch);
	}
	temp1=head;
	while(temp1!=NULL)
	{
		temp2=temp1->next;
		while (temp2!=NULL)
		{
			if(temp1->ratio<temp2->ratio)
			{
				flag1=temp1->item;
				temp1->item=temp2->item;
				temp2->item=flag1;
				flag2=temp1->weight;
				temp1->weight=temp2->weight;
				temp2->weight=flag2;
				flag3=temp1->profit;
				temp1->profit=temp2->profit;
				temp2->profit=flag3;
				flag4=temp1->ratio;
				temp1->ratio=temp2->ratio;
				temp2->ratio=flag4;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("item is:%c\nweight is:%d\nprofit is:%d\nratio is:%f\n",temp->item,temp->weight,temp->profit,temp->ratio);
		temp=temp->next;
	}
	capacity2=capacity1=capacity;
	temp=head;
	while(temp!=NULL)
	{
		if(capacity1>=temp->weight)
		{
			knapsack1[i++]=temp->item;
			maxprofit1=maxprofit1+temp->profit;
			len1=len1+1;
			capacity1=capacity1-temp->weight;
				//capacity=capacity-temp->weight;
				//break;
		}
		temp=temp->next;
	}
	temp=head;
	while(capacity2>0)
	{
		if(capacity2>=temp->weight)
		{
			knapsack2[j++]=temp->item;
			maxprofit2=maxprofit2+temp->profit;
			len2=len2+1;
			capacity2=capacity2-temp->weight;
		}
		else
		{
			len2=len2+1;
			maxprofit2=maxprofit2+((capacity2)*temp->ratio);
			knapsack2[j++]=temp->item;
			capacity2=0;
		}
	temp=temp->next;
	}
	printf("Items in knapsack are in case of 0/1:");
	for(i=0;i<len1;i++)
		printf("%c->",knapsack1[i]);
	printf("\n");
	printf("Maximum profit in 0/1 is:%d\n",maxprofit1);
	printf("Remaining place in knapsack in case of 0/1 is:%d\n",capacity1);
	printf("Items in knapsack are in case of fraction:");
	for(i=0;i<len2;i++)
		printf("%c->",knapsack2[i]);
	printf("\n");
	printf("Maximum profit in fraction is:%f\n",maxprofit2);
	printf("Remaining place in knapsack in case of fraction:%d",capacity2);
	}

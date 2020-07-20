#include <stdio.h>
#include <stdlib.h>
typedef struct mdr{
	int job;
	int deadline;
	int profit;
	struct mdr *next;
	}node;
	node *head,*temp,*t,*temp1,*temp2;
	int profitorder[20];
	int nonexecute[20];
	void main(){
		int ch,flag1,flag2,flag3,max,i,k=0,j,maxprofit=0,len=0,l=0;
		printf("0 for stop creating node\n1 for creating node\n");
		printf("Enter user choice:");
		scanf("%d",&ch);
		while(ch)
		{
			t=(node *)malloc(sizeof(node));
			t->next=NULL;
			printf("Enter job number  and deadline and profit:");
			scanf("%d%d%d",&t->job,&t->deadline,&t->profit);
			if(head==NULL)
			{
				head=t;
			}
			else
			{
				temp=head;
				while(temp->next)
					temp=temp->next;
				temp->next=t;
			}
		printf("Enter user choice:");
		scanf("%d",&ch);
		}		
	temp1=head;
		while(temp1!=NULL)
		{
			temp2=temp1->next;
			while (temp2!=NULL)
			{
				if(temp1->profit<temp2->profit)
				{
					flag1=temp1->profit;
					temp1->profit=temp2->profit;
					temp2->profit=flag1;
					flag2=temp1->job;
					temp1->job=temp2->job;
					temp2->job=flag2;
					flag3=temp1->deadline;
					temp1->deadline=temp2->deadline;
					temp2->deadline=flag3;
					}
				temp2=temp2->next;
			}
			temp1=temp1->next;
		}
	temp=head;
	while(temp!=NULL)
		{
			len=len+1;
			//printf("Job is:%d\nDeadline is:%d\nProfit is:%d\n",temp->job,temp->deadline,temp->profit);
			temp=temp->next;
		}
	temp=head;
	max=temp->deadline;
	while(temp!=NULL)
	{
		if(temp->deadline>max)
			max=temp->deadline;
		temp=temp->next;
	}
	//printf("Max deadline:%d",max);
	temp=head;
	while(temp!=NULL)
	{
		if(profitorder[temp->deadline]==0)
		{
			profitorder[temp->deadline]=temp->job;
			maxprofit=maxprofit+temp->profit;
			//printf("%d",maxprofit);
		}
		else
		{
			for(i=(temp->deadline)-1;i>0;i--)
			{
				if(profitorder[i]==0)
				{
					profitorder[i]=temp->job;
					maxprofit=maxprofit+temp->profit;
					//printf("%d",maxprofit);
					break;
				}
				/*else
				{
					nonexecute[k]=temp->job;
					k++;
				}*/
			}
		}
		temp=temp->next;
	}
	printf("Executed jobs are:");
	for(i=1;i<=max;i++)
		{
		l=l+1;
		printf("%d->",profitorder[i]);
		}
	printf("\n");
	/*printf("Nonexeuted jobs are:");
	for(i=0;i<len-l;i++)
		{
		printf("%d->",nonexecute[i]);	
		}
	printf("\n");*/
	printf("Maximum profit is:%d",maxprofit);
	}

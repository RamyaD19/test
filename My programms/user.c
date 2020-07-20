#include <stdio.h>
int main(){
	int len,que,i,j,index,count;
	char str[20];
	char cha;
	v:
	{
	printf("Enter string length:");
	scanf("%d",&len);
	}
	if(len>0&&len<=10000)
		{
		printf("Enter string:");
		scanf("%s",str);
		}
	else
		{
		printf("String lenght is 1 to 10000\n");
		goto v;
		}
	q:
	{
	printf("Enter no.of questions:");
	scanf("%d",&que);
	}
	if(que>0&&que<=50000)
		{
		for(j=0;j<que;j++)
		{
		printf("Enter index postion in string:");
		scanf("%d",&index);
		cha=str[index];
		count=0;
		for(i=0;i<index;i++)
			{
			if(str[i]==cha)
				count=count+1;
			}
		printf("%c count is:%d\n",cha,count);
		}
		}
	else
		{
		printf("Length range is 1 to 50000\n");
		goto q;
		}
	}

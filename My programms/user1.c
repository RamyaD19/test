#include <stdio.h>
#include <string.h>
int ask();
int qno();
int len,que,i,j,ind,count;
char str[10000];
char cha;
int main(){
	ask();
	printf("Enter string:");
	scanf("%s",str);
	qno();
	for(j=0;j<que;j++)
		{
		printf("Enter index postion in string:");
		scanf("%d",&ind);
		cha=str[ind];
		count=0;
		for(i=0;i<ind;i++)
			{
			if(str[i]==cha)
				count=count+1;
			}
		printf("%c count is:%d\n",cha,count);
		}
	}
int ask(){
	printf("Enter string lenght:");
	scanf("%d",&len);
	if(len>0&&len<=10000)
		return 0;
	else
		ask();
	}
int qno(){
	printf("Enter no.of questions:");
	scanf("%d",&que);
	if(que>0&&len<=50000)
		return 0;
	else
		qno();
	}

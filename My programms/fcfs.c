#include <stdio.h>
int findindex();
int AT[10],i,n,flag[10];
int main(){
	int P[10],ET[10],CT[10],TAT[10],WT[10],temp=0;
	float MTAT[10];
	int j,k,min,ctavg=0,tatavg=0,wtavg=0,mtatavg=0;
	printf("Enter no.of procedures:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter proceudure, arrival time and execution time:");
		scanf("%d%d%d",&P[i],&AT[i],&ET[i]);
		flag[i]=0;
	}
	/*for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(AT[i]>AT[j])
			{
				int temp=P[i]; P[i]=P[j]; P[j]=temp;
				temp=AT[i]; AT[i]=AT[j]; AT[j]=temp;
				temp=ET[i]; ET[i]=ET[j]; ET[j]=temp;
			}
		}
	}*/
	for(int k=0;k<n;k++)
	{
		i=findindex();
		flag[i]=1;
		if(k==0)
			temp=AT[i]+ET[i];
		else
			temp=temp+ET[i];
		CT[i]=temp;
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-ET[i];
		MTAT[i]=(float)TAT[i]/ET[i];
		ctavg=ctavg+CT[i];
		tatavg=tatavg+TAT[i];
		wtavg=wtavg+WT[i];
		mtatavg=mtatavg+MTAT[i];
	}
	printf("Process\tAT\tET\tCT\tTAT\tWT\tMTAT\n");
	for(int k=0;k<n;k++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%f\n",P[k],AT[k],ET[k],CT[k],TAT[k],WT[k],MTAT[k]);
	printf("Average compilation time is:%f\nAverage turn around time is:%f\nAverage waiting time is:%f\nAverage mean turn around time is:%f\n",(float)ctavg/n,(float)tatavg/n,(float)wtavg/n,(float)wtavg/n);
}
int findindex()
{
	int min=10;
	AT[min]=50;
	for(int j=0;j<n;j++)
	{
		if(flag[j]==0&&AT[j]<AT[min])
			min=j;
	}
	return min;
}

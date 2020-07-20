#include <stdio.h>
int i,n;
int main(){
	int P[10],AT[10],ET[10],CT[10],TAT[10],WT[10];
	float MTAT[10],mtatavg=0;
	int j,k,min=0,ctavg=0,tatavg=0,wtavg=0,temp;
	printf("Enter no.of procedures:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter proceudure, arrival time and execution time:");
		scanf("%d%d%d",&P[i],&AT[i],&ET[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ET[i]>ET[j])
			{
				int temp=P[i]; P[i]=P[j]; P[j]=temp;
				temp=AT[i]; AT[i]=AT[j]; AT[j]=temp;
				temp=ET[i]; ET[i]=ET[j]; ET[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(AT[min]>AT[i])
			min=i;
	}
	CT[min]=AT[min]+ET[min];
	temp=CT[min];
	TAT[min]=CT[min]-AT[min];
	WT[min]=TAT[min]-ET[min];
	MTAT[min]=(float)TAT[min]/ET[min];
	for(i=0;i<n;i++)
	{
		if(i!=min)
		{
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
	}
	printf("Process\tAT\tET\tCT\tTAT\tWT\tMTAT\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%f\n",P[i],AT[i],ET[i],CT[i],TAT[i],WT[i],MTAT[i]);
	printf("Average compilation time is:%f\n",(float)(ctavg+CT[min])/n);
	printf("Average turn around time is:%f\n",(float)(tatavg+TAT[min])/n);
	printf("Average waiting time is:%f\n",(float)(wtavg+WT[min])/n);
	printf("Average mean turn around time is:%f\n",(float)(mtatavg+MTAT[min])/n);
}

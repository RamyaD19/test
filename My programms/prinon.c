#include <stdio.h>
int i,n,flag[10],pri[10],AT[10],min=0;
int findindex(int);
int main(){
	int P[10],ET[10],CT[10],TAT[10],WT[10],po[10],c=0,rt[10];
	float MTAT[10],mtatavg=0;
	int j,k,ctavg=0,tatavg=0,wtavg=0,rtavg=0,temp;
	printf("Enter no.of procedures:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter proceudure,arrival time,execution time and priority:");
		scanf("%d%d%d%d",&P[i],&AT[i],&ET[i],&pri[i]);
		flag[i]=0;
	}
	/*for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pri[i]<pri[j])
			{
				int temp=P[i]; P[i]=P[j]; P[j]=temp;
				temp=AT[i]; AT[i]=AT[j]; AT[j]=temp;
				temp=ET[i]; ET[i]=ET[j]; ET[j]=temp;
				temp=pri[i]; pri[i]=pri[j];pri[j]=temp;
			}
		}
	}*/
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
	po[c++]=P[min];
	rt[min]=0;
	flag[min]=1;
	for(j=0;j<n;j++)
	{
		if(j!=min)
		{
			i=findindex(temp);
			flag[i]=1;
			rt[i]=temp-AT[i];
			temp=temp+ET[i];
			CT[i]=temp;
			TAT[i]=CT[i]-AT[i];
			WT[i]=TAT[i]-ET[i];
			MTAT[i]=(float)TAT[i]/ET[i];
			ctavg=ctavg+CT[i];
			tatavg=tatavg+TAT[i];
			wtavg=wtavg+WT[i];
			mtatavg=mtatavg+MTAT[i];
			rtavg=rtavg+rt[i];
			po[c++]=P[i];
		}
	}
	printf("Process\tAT\tET\tCT\tTAT\tWT\tRT\tMTAT\n");
	for(j=0;j<n;j++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\n",P[j],AT[j],ET[j],CT[j],TAT[j],WT[j],rt[j],MTAT[j]);
	printf("Process order:");
	for(j=0;j<n;j++)
		printf("p%d->",po[j]);
	printf("\nAverage compilation time is:%f\nAverage turn around time is:%f\nAverage waiting time is:%f\nAverage mean turn around time is:%f\nAverage response time:%f\n",(float)(ctavg+CT[min])/n,(float)(tatavg+TAT[min])/n,(float)(wtavg+WT[min])/n,(float)(mtatavg+MTAT[min])/n,(float)rtavg/n);
}
int findindex(int q)
{
	int m=10;
	pri[m]=-1;
	for(int k=0;k<n;k++)
	{
		if(AT[k]<=q&&flag[k]==0&&pri[m]<pri[k])
			m=k;
	}
	return m;
}

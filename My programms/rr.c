#include <stdio.h>
int findindex(int);
int p[10],n;
int main()
{
	int at[10],et[10],ct[10],wt[10],tat[10],rt[10],i,j,k,m,temp=0,tq,gc[30],ettemp[10],c=0,index;
	float mtat[10],mtatavg=0;
	int ctavg=0,wtavg=0,tatavg=0,rtavg=0;
	printf("Enter no.of procedures:");
	scanf("%d",&n);
	int flag[n];
	for(i=0;i<n;i++)
	{
		printf("Enter proceudure, arrival time and execution time:");
		scanf("%d%d%d",&p[i],&at[i],&et[i]);
		ettemp[i]=et[i];
		flag[i]=0;
		rt[i]=-1;
	}
	printf("Enter time quantam:");
	scanf("%d",&tq);
	for(i=0;i<30;i++)
		gc[i]=-1;
	int min=0;
	for(i=0;i<n;i++)
	{
		if(at[min]>at[i])
			min=i;
	}
	gc[c++]=p[min];
	flag[min]=1;
	temp=at[min];
	for(j=0;gc[j]!=-1;j++)
	{
		for(k=0;k<n;k++)
		{
			if(gc[j]==p[k])
				{
				index=k;
				break;
				}
		}
		if(rt[index]==-1)
		{
			rt[index]=temp-at[index];
			rtavg=rtavg+rt[index];
		}
		if(ettemp[index]<=tq)
		{
			if(index==min&&j==0)
				temp=at[index]+et[index];
			else
				temp=temp+ettemp[index];
			ettemp[index]=0;
			ct[index]=temp;
			tat[index]=ct[index]-at[index];
			wt[index]=tat[index]-et[index];
			mtat[index]=(float)tat[index]/et[index];
			ctavg=ctavg+ct[index];
			tatavg=tatavg+tat[index];
			wtavg=wtavg+wt[index];
			mtatavg=mtatavg+mtat[index];
		}
		else
		{
			if(index==min&&j==0)
				temp=at[index]+tq;
			else
				temp=temp+tq;
			ettemp[index]=ettemp[index]-tq;
		}
		m=c;
		for(i=0;i<n;i++)
		{
			if(at[i]<=temp&&flag[i]!=1)
			{
				gc[c++]=p[i];
				flag[i]=1;
			}
		}
		for(int q=m;q<c;q++)
		{
			int u=findindex(gc[q]);
			for(int r=q+1;r<c;r++)
			{
				int v=findindex(gc[r]);
				if(at[u]>at[v])
				{
					int var=gc[q];
					gc[q]=gc[r];
					gc[r]=var;
				}
			}
		}
		if(ettemp[index]!=0)
			gc[c++]=p[index];
	}
	printf("P.no\tAT\tET\tCT\tTAT\tWT\tRT\tMTAT\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\n",p[i],at[i],et[i],ct[i],tat[i],wt[i],rt[i],mtat[i]);
	printf("Process order:");
	for(int w=0;w<c;w++)
		printf("p%d->",gc[w]);
	printf("\nAverage complition time:%f\nAvergage turn around time:%f\nAverage waiting time:%f\nAverage mean turn around time:%f\nAverage response time:%f\n",(float)ctavg/n,(float)tatavg/n,(float)wtavg/n,mtatavg/n,(float)rtavg/n);
	}
int findindex(int q)
{
	for(int i=0;i<n;i++)
	{
		if(q==p[i])
			return i;
	}
}

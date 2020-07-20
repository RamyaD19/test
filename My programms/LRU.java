import java.util.Scanner;
class LRU{
	public static void main(String[]args)
	{
		int i,c=0,k,d,count=0,j,flag1,flag2;
		Scanner obj=new Scanner(System.in);
		System.out.print("Enter number of pages:");
		int p=obj.nextInt();
		int page[]=new int[p];
		System.out.print("Enter frame size:");
		int fsize=obj.nextInt();
		int frame[]=new int[fsize];
		int recent[]=new int[fsize];
		System.out.println("Enter pages");
		for(i=0;i<p;i++)
			page[i]=obj.nextInt();
		for(i=0;i<fsize;i++)
			frame[i]=-1;
		for(i=0;i<p;i++)
		{
			flag1=flag2=0;
			for(j=0;j<fsize;j++)
			{
				if(frame[j]==page[i])
					flag1=flag2=1;
			}
			for(k=0;k<fsize;k++)
				recent[k]=-1;
			if(flag1!=1)
			{
				for(k=0;k<fsize;k++)
				{
					if(frame[k]==-1)
					{
						frame[k]=page[i];
						flag2=1;
						c++;
						break;
					}
				}
			}
			if(flag2!=1)
			{
				d=0;
				count=0;
				for(k=i-1;k>=0;k--)
				{
					int f=0;
					for(j=0;j<fsize;j++)
					{
						if(recent[j]==page[k])
						{
							f=1;
							break;
						}
					}
					
					if(f!=1)
					{
						recent[d++]=page[k];
						count++;
						if(count==fsize)
							break;
					}
				}
				int val=recent[d-1];
				for(j=0;j<fsize;j++)
				{
					if(frame[j]==val)
					{
						frame[j]=page[i];
						c++;
					}
				}
			}
		for(int arr:frame)
			System.out.print(arr+" ");
			System.out.print("\n");
		}	
		System.out.println("Page fault is:"+c);
	}
}

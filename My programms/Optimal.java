import java.util.Scanner;
class Optimal
{
	public static void main(String[]args)
	{
		int i,j,flag1,flag2,c=0;
		Scanner obj=new Scanner(System.in);
		System.out.print("Enter number of pages:");
		int p=obj.nextInt();
		System.out.print("Enter frame size:");
		int fsize=obj.nextInt();
		int page[]=new int[p];
		int frame[]=new int[fsize];
		System.out.println("Enter pages");
		for(i=0;i<p;i++)
			page[i]=obj.nextInt();
		for(i=0;i<fsize;i++)
			frame[i]=-1;
		System.out.println("*-1 shows that the block is empty*");
		for(i=0;i<p;i++)
		{
			flag1=flag2=0;
			for(j=0;j<fsize;j++)
			{
				if(frame[j]==page[i])
				{
					flag1=flag2=1;
					break;
				}
			}
			if(flag1!=1)
			{
				for(j=0;j<fsize;j++)
				{
					if(frame[j]==-1)
					{
						frame[j]=page[i];
						c++;
						flag2=1;
						break;
					}
				}
			}
			if(flag2!=1)
			{
				int f=p,count,min=frame[0];
				for(j=0;j<fsize;j++)
				{
					count=0;
					for(int k=i;k<p;k++)
					{
						if(frame[j]==page[k])
						{
							count++;
						}
					}
					if(count<f)
					{
						min=frame[j];
						f=count;
					}
				}
				for(j=0;j<fsize;j++)
				{
					if(frame[j]==min)
					{
						frame[j]=page[i];
						c++;
						break;
					}
				}
			}
			for(int k:frame)
				System.out.print(k+" ");
				System.out.print("\n");
		}
		System.out.println("Page fault is:"+c);
	}
}

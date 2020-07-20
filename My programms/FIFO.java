import java.util.Scanner;
class FIFO{
	public static void main(String[]args)
	{
		int i,k=0,c=0;
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter no.of pages:");
		int p=obj.nextInt();
		int page[]=new int[p];
		System.out.println("Enter frame size:");
		int fsize=obj.nextInt();
		int frame[]=new int[fsize];
		System.out.println("Enter pages");
		for(i=0;i<p;i++)
			page[i]=obj.nextInt();
		for(i=0;i<fsize;i++)
			frame[i]=-1;
		for(i=0;i<p;i++)
		{
			int flag=0;
			for(int j=0;j<fsize;j++)
			{
				if(frame[j]==page[i])
					flag=1;
			}
			if(flag!=1)
			{
				frame[k]=page[i];
				k=(k+1)%fsize;         //k=k+1; if(k==fsize) k=0;
				c++;
			}
		for(int arr:frame)
			System.out.print(arr+" ");
			System.out.println("\n");
		}
		System.out.println("Page fault is:"+c);
	}
}

import java.io.*;
import java.util.*;

class ZombieApocalypse
{
	static class Beam
	{
		int l;
		int r;
		long k;

		public Beam(int l,int r,long k)
		{
			this.l=l;
			this.r=r;
			this.k=k;
		}
	}

	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			String s[]=br.readLine().split(" ");
			int n=Integer.parseInt(s[0]);
			int m=Integer.parseInt(s[1]);
			long Z[]=new long[n];
			s=br.readLine().split(" ");
			for(int i=0;i<n;++i)
			{
				Z[i]=Long.parseLong(s[i]);
			}

			ArrayList<Beam> list=new ArrayList<>();

			for(int i=0;i<m;++i)
			{
				s=br.readLine().split(" ");
				list.add(new Beam(Integer.parseInt(s[0])-1,Integer.parseInt(s[1])-1,Long.parseLong(s[2])));				
			}

			Collections.sort(list,new Comparator<Beam>()
			{
				public int compare(Beam a,Beam b)
				{
					if(a.l==b.l)
						return b.r-a.r;
					return a.l-b.l;
				}
			});

			PriorityQueue<Beam> pq=new PriorityQueue<>(m,new Comparator<Beam>()
				{
					public int compare(Beam a,Beam b)
					{
						return b.r-a.r;
					}
				});

			boolean flag=false;
			long result=0;

			long diff[]=new long[n+1];

			// diff[0]=Z[0];
			// for(int i=1;i<n;++i)
			// {
			// 	diff[i]=Z[i]-Z[i-1];
			// }

			int j=0;
			long ext=0;
			for(int i=0;i<n;++i)
			{
				//Z[i]=(i==0)?Z[0]:(Z[i-1]+diff[i]);
				Z[i]-=ext;
				while(j<m && list.get(j).l<=i)
				{
					pq.add(list.get(j));
					++j;
				}

				while(Z[i]>0 && !pq.isEmpty())
				{
					Beam temp=pq.poll();

					if(temp.r<i)
						continue;

					if(temp.k<=Z[i])
					{
						result+=temp.k;
						//diff[temp.l]+=-temp.k;
						ext+=temp.k;
						diff[temp.r]+=temp.k;
						Z[i]-=temp.k;
					}
					else
					{
						result+=Z[i];
						//diff[temp.l]+=-Z[i];
						ext+=Z[i];
						diff[temp.r]+=Z[i];
						temp.k-=Z[i];
						pq.add(temp);
						Z[i]=0;
					}
				}

				if(Z[i]>0)
				{
					flag=true;
					break;
				}
				ext-=diff[i];
			}
			
			if(flag==false)
			{
				System.out.println("YES "+result);
			}
			else
			{
				System.out.println("NO");
			}
		}
	}
}

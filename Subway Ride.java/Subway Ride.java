/*input
3 3
1 7
10 5
8 9
3 0
3 1 1
6 2 1 2
 
*/
	import java.io.ByteArrayInputStream;
	import java.io.IOException;
	import java.io.InputStream;
	import java.io.PrintWriter;
	import java.util.*;
	//Exponential Learning or Nothing
	public class Main {
	 
	   InputStream is;
		PrintWriter out;
		String INPUT = ""; 
	//class Declaration
		static int n,m;
static ArrayList<HashMap<Integer,HashSet<Integer>>> tp;
static int end=0,start=0,ans=0;

	static class pii implements Comparable<pii>{
	    int x,y;
	    pii (int i,int j)
	    { x=i; y=j;}
	    public int compareTo(pii p){
	        if(this.x!=p.x) { return this.x-p.x;}
	        else { return this.y-p.y;}
	    }
	    public int hashCode() { return (x+" "+y).hashCode();}
	    public String toString(){ return x+" "+y;} 
	    public boolean equals(pii x){ return (x.x==this.x&&x.y==this.y);}
	}
int[][] dp;	
void solve(){ 
	      n=ni();m=ni();
	      
tp=new ArrayList<>();
 

 
 
 for(int i=0;i<n;++i){
  tp.add(new HashMap<Integer,HashSet<Integer> >());
}
 for(int i=0;i<m;++i){
 int u=ni()-1,v=ni()-1,w=ni();
 
 HashMap<Integer,HashSet<Integer>> hm=tp.get(u);
 HashMap<Integer,HashSet<Integer>> hm2=tp.get(v);
 
 
 
 if(!hm.containsKey(v)){
 	HashSet<Integer> hs=new HashSet<>();
 	hs.add(w);
 	hm.put(v,hs);
 }
 else{
 	hm.get(v).add(w);
 }
 
 
 if(!hm2.containsKey(u)){
 	HashSet<Integer> hs=new HashSet<>();
 	hs.add(w);
 	hm2.put(u,hs);
 }
 else{
 	hm2.get(u).add(w);
 }
 	
}
dp=new int[n][n];
for(int i=0;i<n;++i)
Arrays.fill(dp[i],-1);

for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        int min=Math.min(i,j);
        int max=Math.max(i,j);
        if(dp[min][max]==-1){
            	start=min;end=max;ans=0;
            	traverse(min,-1,-1,false,0);
            	//System.out.println(ans);
            	dp[min][max]=ans-1;
        }
    }
}
// for(int i=0;i<n;++i)
// System.out.println(Arrays.toString(dp[i]));
int q=ni();
for(int i=0;i<q;++i){
	int x=ni()-1,y=ni()-1;
	if(x!=y){
	    int min=Math.min(x,y);
        int max=Math.max(x,y);
    System.out.println(dp[min][max]);
	    
	}
	else System.out.println(0);
}
        
    
}
 static void traverse(int s,int p,int pc,boolean flag,int a){
	//pn("s,p,pc,a "+s+" "+p+" "+pc+" "+a);
	HashMap<Integer,HashSet<Integer>> hm=tp.get(s);
	Set<Integer> key=hm.keySet();
	if(s==end){
		ans=a;
		return;
	}
	if(s==start){
		int fa=-1;
		for(int x:key){
		HashSet<Integer> colour=hm.get(x);
		for(int y:colour){
			ans=0;
			traverse(x,s,y,false,a+1);
 
			fa=Math.max(fa,ans);	
		}
 
	}
		ans=fa;
		return;
	}
	
	for(int x:key){
		if(x==p) continue;
		HashSet<Integer> colour=hm.get(x);
		int ind=0;
		for(int y:colour){
			ind++;
			
 
			if(y!=pc){
			    if(ind<colour.size())
				traverse(x,s,y,true,a+1);
				else traverse(x,s,y,false,a+1);
				break;
			}
		
			
			if(ind==colour.size()&&(!flag)){
				traverse(x,s,y,false,a);
			}
			else traverse(x,s,y,false,a+1);
			
		}
	}
 
 
}
 
int min(int[] arr)
{
	    int min=Integer.MAX_VALUE;
	    for(int i=0;i<arr.length;++i)
	    {
	        if(min>arr[i]) min=arr[i];
	    }
	    return min;
	}
	int max(int[] arr)
	{
	    int max=Integer.MIN_VALUE;
	    for(int i=0;i<arr.length;++i)
	    {
	        if(max<arr[i]) max=arr[i];
	    }
	    return max;
	}
	 long lcm(long x,long y){
		long g=gcd(x,y);
		long ans=((long)x*(long)y)/(long)g;
		return ans;
	}
	 long gcd(long x,long y)
	{
	  if(y==0) return x;
	  return gcd(y,x%y);
	}
	static long nCr(long n,long rc)
	{
	 long r=Math.min(rc,n-rc);
	 long ans=1;
	 for(int i=1,j=(int)n;i<=r;++i,--j)
	 {
	   ans=(ans*(long)j)/((long)i);
	 }
	  return ans;
	  
}
 
	void run() throws Exception
	{
			is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
			out = new PrintWriter(System.out);
			
			long s = System.currentTimeMillis();
			solve();
			out.flush();
			if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
	}
		
		
		public static void main(String[] args) throws Exception { new Main().run(); }
		
	//output methods
	private void pn(Object o)
	{
		out.println(o);
	}
	private void p(Object o)
	{
		out.print(o);
	}
 
 
 
	//input methods
			private byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;
		
 
		private int readByte()
		{
			if(lenbuf == -1)throw new InputMismatchException();
			if(ptrbuf >= lenbuf){
				ptrbuf = 0;
				try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
				if(lenbuf <= 0)return -1;
			}
			return inbuf[ptrbuf++];
		}
		
		private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
		private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
		
		private double nd() { return Double.parseDouble(ns()); }
		private char nc() { return (char)skip(); }
		
		private String ns()
		{
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		
		private char[] ns(int n)
		{
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while(p < n && !(isSpaceChar(b))){
				buf[p++] = (char)b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
			
		private char[][] nm(int n, int m)
		{
			char[][] map = new char[n][];
			for(int i = 0;i < n;i++)map[i] = ns(m);
			return map;
		}
		
		private int[] na(int n)
		{
			int[] a = new int[n];
			for(int i = 0;i < n;i++)a[i] = ni();
			return a;
		}
		
		private int ni()
		{
			int num = 0, b;
			boolean minus = false;
			while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
			if(b == '-'){
				minus = true;
				b = readByte();
			}
			
			while(true){
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
		
		private long nl()
		{
			long num = 0;
			int b;
			boolean minus = false;
			while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
			if(b == '-'){
				minus = true;
				b = readByte();
			}
			
			while(true){
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
		
		private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }
	} 

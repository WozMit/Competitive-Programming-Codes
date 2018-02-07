//package new_pack;
import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Reader r = new Reader();
		int t = r.nextInt();
		while(t-- > 0){
			int n = r.nextInt(), gg = 0;
			BigInteger f = BigInteger.ONE;
			for(int i=2; i<=n; i++) f = f.multiply(BigInteger.valueOf(i));
			while(f.compareTo(BigInteger.ZERO) > 0){
				gg += Integer.parseInt(f.mod(BigInteger.TEN).toString());
				f = f.divide(BigInteger.TEN);
			}
			System.out.println(gg);
		}
	}
	//Faster I/O
	public static class Reader{
		BufferedReader br;
		StringTokenizer st;
		public Reader(){ br = new BufferedReader(new InputStreamReader(System.in)); }
		String next(){
			while(st == null || !st.hasMoreElements()){
				try{ st = new StringTokenizer(br.readLine()); }
				catch(IOException e){ e.printStackTrace(); }
			}
			return st.nextToken();
		}
		int nextInt(){ return Integer.parseInt(next()); }
		long nextLong(){ return Long.parseLong(next()); }
		double nextDouble(){ return Double.parseDouble(next()); }
		BigInteger nextBigInteger(){ return new BigInteger(next()); }
		String nextLine(){
			String str = "";
			try{ str = br.readLine(); }
			catch(IOException e){ e.printStackTrace(); }
			return str;
		}
	}
}
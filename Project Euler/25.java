/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger a = new BigInteger("1"), b = new BigInteger("1"), c;
		int k = b.toString().length(), h = 2;
		while(k < 1000){
			c = new BigInteger(a.toString());
			a = new BigInteger(b.toString());
			b = b.add(c);
			k = b.toString().length();
			h++;
		}
		System.out.println(h);
	}
}

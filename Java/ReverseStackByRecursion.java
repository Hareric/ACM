package ch1;

import java.util.Stack;

public class ReverseStackByRecursion
{
	public static void recursion(Stack<Integer> sOrigin, Stack<Integer> sReversed)
	{
		if (!sOrigin.isEmpty())
		{
			sReversed.push(sOrigin.pop());
			recursion(sOrigin, sReversed );
		}
	}
	
	
	
	public static void main(String[] args)
	{
		Stack<Integer> s1 = new Stack<Integer>(), s2 = new Stack<Integer>();
		s1.push(1);
		s1.push(2);
		s1.push(3);
		s1.push(4);
		
		
		
		
		System.out.println(s1.toString());
		
		recursion(s1,s2);
		System.out.println(s1.toString());
		System.out.println(s2.toString());
		
	}
}

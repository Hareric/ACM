package ch1;

import java.util.*;

public class SortStackByOtherStack
{
	public static void main(String[] args)
	{
		Stack<Integer> s = new Stack<Integer>();
		s.push(2);
		s.push(53);
		s.push(6);
		s.push(4);
		s.push(26);
		s.push(23);
		s.push(553);
		s.push(63);
		s.push(46);
		s.push(268);
		s.push(23);
		s.push(33);
		s.push(65);
		s.push(46);
		s.push(263);
		Stack<Integer> sSort = new Stack<Integer>();
		int tmp;
		while (!s.isEmpty())
		{
			tmp = s.pop();
			if (sSort.isEmpty())
			{
				sSort.push(tmp);
			} else
			{
				while (!sSort.isEmpty() && sSort.peek() > tmp)
				{
					s.push(sSort.pop());
				}
				sSort.push(tmp);
			}
		}

		System.out.println(sSort.toString());

	}
}

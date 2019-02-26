package ch1;

import java.util.ArrayDeque;
import java.util.Deque;

public class GenerateMaxWindowArray
{
	public static void main(String[] args)
	{
		int arr[] = { 4, 3, 5, 4, 3, 3, 6, 7 ,10, 100 ,10};
		Deque<Integer> qMax = new ArrayDeque<Integer>();
		int wSize = 3;
		int[] window = new int[arr.length - wSize + 1];

		for (int i = 0; i < arr.length; i++)
		{
			if (qMax.isEmpty())
			{
				qMax.addLast(i);
			} else
			{
				while (!qMax.isEmpty() && (arr[qMax.peekLast()] < arr[i]))
				{
					qMax.pollLast();
				}
				qMax.addLast(i);
			}
			if (i >= wSize - 1)
			{
				if (qMax.peekFirst() < i - wSize + 1)
				{
					qMax.pollFirst();
				}
				window[i - wSize + 1] = arr[qMax.peekFirst()];
			}
		}
		for (int i=0; i<window.length; i++)
		{
			System.out.print(window[i] + " ");
		}	
	}
}

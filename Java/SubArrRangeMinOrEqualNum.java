package ch1;

import java.util.ArrayDeque;
import java.util.LinkedList;

public class SubArrRangeMinOrEqualNum
{
	/**
	 * 
	 * @param n
	 * @return 1 + 2 + 3 + ... + n
	 */
	public static int sum(int n)
	{
		return n * (n + 1) / 2;
	}

	

	public static int getNumSample(int[] arr, int num)
	{
		if (arr == null || arr.length == 0)
		{
			return 0;
		}
		LinkedList<Integer> qmin = new LinkedList<Integer>();
		LinkedList<Integer> qmax = new LinkedList<Integer>();
		int i = 0;
		int j = 0;
		int res = 0;
		while (i < arr.length)
		{
			while (j < arr.length)
			{

				while (!qmin.isEmpty() && arr[qmin.peekLast()] >= arr[j])
				{
					qmin.pollLast();
				}
				qmin.addLast(j);
				while (!qmax.isEmpty() && arr[qmax.peekLast()] <= arr[j])
				{
					qmax.pollLast();
				}
				qmax.addLast(j);

				if (arr[qmax.getFirst()] - arr[qmin.getFirst()] > num)
				{
					break;
				}
				j++;
			}
			if (qmin.peekFirst() == i)
			{
				qmin.pollFirst();
			}
			if (qmax.peekFirst() == i)
			{
				qmax.pollFirst();
			}
			res += j - i;

			i++;
		}
		return res;
	}

	public static int getNum(int[] arr, int num)
	{
		int res = 0;
		ArrayDeque<Integer> qMax = new ArrayDeque<Integer>();
		ArrayDeque<Integer> qMin = new ArrayDeque<Integer>();
		int i = 0;
		for (int j = 0; j < arr.length; j++)
		{
			if (qMax.isEmpty() && qMin.isEmpty())
			{
				qMax.add(j);
				qMin.add(j);
				continue;
			} else
			{
				if (Math.abs(arr[j] - arr[qMax.peekFirst()]) > num || Math.abs(arr[j] - arr[qMin.peekFirst()]) > num)
				{
					res += (j - i);
					i++;
					if (qMax.peekFirst() < i)
					{
						qMax.pollFirst();
					}
					if (qMin.peekFirst() < i)
					{
						qMin.pollFirst();
					}
					j--;
					continue;
				} else
				{
					while (!qMax.isEmpty() && arr[j] > arr[qMax.peekLast()])
					{
						qMax.pollLast();
					}
					qMax.add(j);
					while (!qMin.isEmpty() && arr[j] < arr[qMin.peekLast()])
					{
						qMin.pollLast();
					}
					qMin.add(j);
				}
			}

		}
		res += sum(arr.length - i);
		return res;
	}

	public static void main(String[] args)
	{
		int[] arr = { 1, 2, 10, 4 };
		int num = 4;

		System.out.println(getNum(arr, num));
		System.out.println(getNumSample(arr, num));

	}

}

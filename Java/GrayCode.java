package lintcode;

import java.util.*;

public class GrayCode
{

	public static List<Integer> recursion(int n, List<Integer> codeList)
	{
		// write your code here
		// System.out.println(codeList.size());
		if (codeList.size() == (int) Math.pow(2, n))
		{

			return codeList;

		}

		List<Integer> codeList2 = new ArrayList<Integer>();
		int[] addNum = { 0, 1, 1, 0 };
		for (int i = 0; i < codeList.size() * 2; i++)
		{
			codeList2.add((codeList.get(i / 2) << 1) + addNum[i % 4]);
		}
		return recursion(n, codeList2);
	}

	public static List<Integer> grayCode(int n)
	{
		// write your code here
		List<Integer> list = new ArrayList<Integer>();
		list.add(0);
		if (n == 0)
			return list;

		list.add(1);
		return recursion(n, list);
	}

	public static void main(String[] args)
	{
		for (int i : grayCode(5))
			System.out.print(i + " ");
	}
}

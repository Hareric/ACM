package ch1;

import java.util.Stack;

/**
 * 
 * @author Har
 *
 */
public class MaxRect
{
	public static int maxSize = 0;

	public static int splitRect(int[][] rect)
	{
		int rectWidth = rect.length;
		int rectLength = rect[0].length;
		int splitRow[] = new int[rectLength];
		for (int i = 0; i < rectWidth; i++)
		{
			for (int j = 0; j < rectLength; j++)
			{
				if (rect[i][j] == 1)
				{
					splitRow[j]++;
				} else
				{
					splitRow[j] = 0;
				}
			}
			getMaxSize(splitRow);
		}
		return maxSize;
	}

	public static int getMaxSize(int splitRow[])
	{
		Stack<Integer> s = new Stack<Integer>();
		int j = 0; // pop出的座标
		int k = 0; // peek的座标
		int tempMax = 0;
		for (int i = 0; i <= splitRow.length; i++)
		{
			if (s.isEmpty() && i < splitRow.length)
			{
				s.push(i);
			} else
			{
				{
					while (!s.isEmpty()
							&& ((i == splitRow.length) || (i < splitRow.length && splitRow[s.peek()] >= splitRow[i])))
					{
						j = s.pop();
						k = s.isEmpty() ? -1 : s.peek();
						tempMax = splitRow[j] * (i - k - 1);
						maxSize = Math.max(tempMax, maxSize);
					}
					if (i != splitRow.length)
					{
						s.push(i);
					}
				}
			}

		}
		return maxSize;
	}

	public static void main(String[] args)
	{
		int rect[][] = { 
				{ 1, 1, 1, 1 }, 
				{ 1, 1, 1, 1 }, 
				{ 1, 1, 1, 1 } ,
				{ 1, 1, 1, 1 }, 
				{ 0, 0, 1, 1 }, 
				{ 1, 1, 1, 1 } , 
				{ 1, 1, 1, 1 }, 
				{ 1, 1, 1, 1 }, 
				{ 1, 1, 1, 1 } 
				};
		
		System.out.println(splitRect(rect));
	}
}

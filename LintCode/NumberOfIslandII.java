package lintcode;

import java.util.*;

class Point
{
	int x;
	int y;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int a, int b)
	{
		x = a;
		y = b;
	}
}

public class NumberOfIslandII
{
	/**
	 * @param n:
	 *            An integer
	 * @param m:
	 *            An integer
	 * @param operators:
	 *            an array of point
	 * @return: an integer array
	 */

	public static void updateSeaAndPoint(List<HashSet<Integer[]>> setList, int[][] sea, int x, int y)
	{
		// 更新sea
		sea[x][y] = 1;
		// 判断周围一圈是有已存在岛屿
		LinkedList<Integer[]> islandList = new LinkedList<Integer[]>();
		if (x > 0)
		{
			if (y > 0)
			{
				if (sea[x - 1][y - 1] == 1)
				{
					islandList.add(new Integer[] { x - 1, y - 1 });
				}
			}
			if (y < sea[0].length - 1)
			{
				if (sea[x - 1][y + 1] == 1)
				{
					islandList.add(new Integer[] { x - 1, y + 1 });
				}
			}
			if (sea[x - 1][y] == 1)
			{
				islandList.add(new Integer[] { x - 1, y });
			}
		}
		if (x < sea.length - 1)
		{
			if (y > 0)
			{
				if (sea[x + 1][y - 1] == 1)
				{
					islandList.add(new Integer[] { x + 1, y - 1 });
				}
			}
			if (y < sea[0].length - 1)
			{
				if (sea[x + 1][y + 1] == 1)
				{
					islandList.add(new Integer[] { x + 1, y + 1 });
				}
			}
			if (sea[x + 1][y] == 1)
			{
				islandList.add(new Integer[] { x + 1, y });
			}
		}
		if (y > 0)
		{
			if (sea[x][y - 1] == 1)
			{
				islandList.add(new Integer[] { x, y - 1 });
			}
		}
		if (y < sea[0].length - 1)
		{
			if (sea[x][y + 1] == 1)
			{
				islandList.add(new Integer[] { x, y + 1 });
			}
		}

		// 若周围无岛屿 setList加一
		if (islandList.size() == 0)
		{
			HashSet<Integer[]> temp = new HashSet<Integer[]>();
			temp.add(new Integer[] { x, y });
			setList.add(temp);
		}else if(islandList.size() == 1) // 周围有一个岛屿， 把新的点加入进该岛屿
		{
			Integer[] temp = new Integer[] { x, y };
			Integer[] neighbourIsland = islandList.peek();
			for (HashSet<Integer[]> t : setList)
			{
				if (t.contains(neighbourIsland))
				{
					t.add(temp);
					break;
				}
			}
		}else  // 周围有多个岛屿， 将他们连接起来成一个set
		{

			List<HashSet<Integer[]>> unionList = new LinkedList<HashSet<Integer[]>>();
			for (Integer[] t : islandList)
			{
				for (HashSet<Integer[]> s : setList)
				{
					if (s.contains(t))
					{
						unionList.add(s);
						setList.remove(s);
						break;
					}
				}
			}
			HashSet<Integer[]> unionSet = new HashSet<Integer[]>();
			for(HashSet<Integer[]> t: unionList)
			{
				unionSet.addAll(t);
			}
			setList.add(unionSet);
			
		}

	}

	public List<Integer> numIslands2(int n, int m, Point[] operators)
	{
		List<Integer> res = new LinkedList<Integer>();
		List<HashSet<Integer[]>> setList = new LinkedList<HashSet<Integer[]>>();
		int[][] sea = new int[n][m];
		for (int i = 0; i < operators.length; i++)
		{
			int x=operators[i].x;
			int y=operators[i].y;
			updateSeaAndPoint(setList, sea, x, y);
			res.add(setList.size());
		}

		return res;
	}
}

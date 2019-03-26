/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */

public class Solution {
	public static boolean isSameLine(Point A, Point B, Point C)
	{
		if (A==C || B==C)
			return false;
		if ((C.x - A.x) * (C.y - B.y) == (C.y - A.y) * (C.x - B.x))
			return true;
		return false;
	}

	static ArrayList<HashSet<Integer>> lineList;

	public static int maxPoints(Point[] points)
	{
		// write your code here
		if (points==null)
		    return 0;
		lineList = new ArrayList<HashSet<Integer>>();
		for (int i = 0; i < points.length; i++)
		{
			for (int j = 0; j < i; j++)
			{
				HashSet<Integer> tmp = new HashSet<Integer>();
				tmp.add(i);
				tmp.add(j);
				lineList.add(tmp);
			}
		}

		for (int i = 0; i < points.length; i++)
		{

			for (HashSet<Integer> l : lineList)
			{
				Iterator<Integer> it = l.iterator();
				Point p1 = points[it.next()];
				Point p2 = points[it.next()];
				while (p1.x==p2.x && p1.y==p2.y && it.hasNext())
				    p2=points[it.next()];
				if (isSameLine(p1, p2, points[i]))
				{
					l.add(i);
				}

			}

		}
		int res = 1;
		for (HashSet<Integer> l : lineList)
		{
			res = Math.max(res, l.size());
		}
		return res;

	}
}

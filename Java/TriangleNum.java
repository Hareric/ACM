package lintcode;

public class TriangleNum
{
	/**
	 * @param triangle:
	 *            a list of lists of integers
	 * @return: An integer, minimum path sum
	 */
	public static int minimumTotal(int[][] triangle)
	{
		// write your code here
		if (triangle.length == 1)
		{
			return triangle[0][0];
		}
		for (int i = 1; i < triangle.length; i++)
		{
			triangle[i][0] += triangle[i - 1][0];
			triangle[i][i] += triangle[i - 1][i-1];
			for (int j = 1; j < i; j++)
			{
				triangle[i][j] = Math.min(triangle[i][j] + triangle[i - 1][j-1], triangle[i][j] + triangle[i - 1][j]);
			}
		}

		int res = triangle[triangle.length - 1][0];
		for (int i = 1; i < triangle[triangle.length - 1].length; i++)
		{
			res = Math.min(res, triangle[triangle.length - 1][i]);
		}
		
//		for (int i=0; i<triangle.length; i++)
//		{
//			for (int j=0; j<=i; j++)
//			{
//				System.out.print(triangle[i][j] + " ");
//			}
//			System.out.println();
//				
//		}
		return res;
	}

	public static void main(String[] args)
	{
		System.out.println(minimumTotal(new int[][] { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } }));
	}
}

import java.util.*;
public class Shoulian
{
	public static void jiaRow(int[] a, int[] b)
	{
		for (int i=0; i<a.length; i++)
		{
			a[i] += b[i];
		}
	}
	
	public static void jianRow(int[] a, int[] b)
	{
		for (int i=0; i<a.length; i++)
		{
			a[i] -= b[i];
		}
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int n, m, c, oneN;
		n = scan.nextInt();
		m = scan.nextInt();
		c = scan.nextInt();
		
		int[][] matrix = new int[n+1][c+1];
		for (int i=1; i<=n; i++)
		{
			oneN = scan.nextInt();
			for (int j=1; j<=oneN; j++)
			{
				matrix[i][scan.nextInt()] = 1;
			}
		}
		if (m > n)
		{
			System.out.println(0);
			return;
		}
		Set<Integer> resSet = new HashSet<Integer>();
		int[] sumRow = new int[c+1]; 
		for (int i=1; i<=m; i++)
		{
			jiaRow(sumRow, matrix[i]);
		}
//		for (int ii=1; ii<=c; ii++)
//		{
//			System.out.print(sumRow[ii] + " ");
//			
//		}
//		System.out.println();
		for (int i=1; i<=n; i++)
		{
			
			for (int j=1; j<=c; j++)
			{
				if (sumRow[j] >= 2)
				{
					resSet.add(j);
				}
			}
			jianRow(sumRow, matrix[i]);
			jiaRow(sumRow, matrix[i+m<=n ? i+m : i+m-n]);
//			for (int ii=1; ii<=c; ii++)
//			{
//				System.out.print(sumRow[ii] + " ");
//				
//			}
//			System.out.println();
		}
		System.out.println(resSet.size());
	}
}

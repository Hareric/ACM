package lintcode;


public class ReversePair
{

	static long res;
	public static long reversePairs(int[] A) {
        // write your code here
		res = 0;
		split(A, 0, A.length-1);
		return res;
    }
	public static void split(int[] A, int start, int end)
	{
		if (start >= end)
		{
			return;
		}else if(end - start == 1)
		{
			merge(A, start, start, end, end);
		}
		else
		{
			int mid = (start + end) / 2;
			split(A, start, mid);
			split(A, mid+1, end);
			merge(A, start, mid, mid+1, end);
		}
		

	}

	public static void merge(int[] A, int startA, int endA, int startB, int endB)
	{
		int aPointer = startA;
		int bPointer = startB;
		int[] mergeArr = new int[endB - startA + 1];
		for (int i = 0; i < mergeArr.length; i++)
		{
			if (aPointer == endA + 1)
			{
				while (bPointer <= endB )
				{
					mergeArr[i] = A[bPointer];
					bPointer++;
					i++;
				}
				break;
			}
			else if (bPointer == endB+1)
			{
				while (aPointer <= endA)
				{
					mergeArr[i] = A[aPointer];
					aPointer++;
					i++;
				}
				break;
			}
			if (A[aPointer] <= A[bPointer])
			{
				mergeArr[i] = A[aPointer];
				aPointer++;
			} else if (A[aPointer] > A[bPointer])
			{
				mergeArr[i] = A[bPointer];
				res += (endA - aPointer + 1);
				bPointer++;
			}
		}
		
		// 排序好的序列 更新至原数组
		for (int i=startA,j=0; i<=endB; i++, j++)
		{
			A[i] = mergeArr[j];
		}
	}
}

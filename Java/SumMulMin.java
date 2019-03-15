import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
 
public class SumMulMin
{
    static Integer[] num;
    public static int getMax(int start, int end)
    {
        if (start == end)
        {
            return num[start] * num[start];
        }else if (start > end)
        {
            return 0;
        }
        int min = num[start];
        int minIndex = start;
        int sum = num[start];
        for (int i=start+1; i<=end; i++)
        {
            if (num[i] < min)
            {
                min = num[i];
                minIndex = i;
            }
            sum += num[i];
        }
        return Math.max(min*sum, Math.max(getMax(start, minIndex-1), getMax(minIndex+1, end)));
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        Integer n = scan.nextInt();
        num = new Integer[n];
        for (int i = 0; i < n; i++)
        {
            num[i] = scan.nextInt();
        }
        System.out.println(getMax(0, n-1));
         
    }
}

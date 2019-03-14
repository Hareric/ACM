
import java.util.*;

public class DayNumInYear
{
	public static boolean isLeap(int year)
	{
		return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0); // 判断是否为闰年
	}

	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int[] dayueNum = { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7 };
		int year;
		int month;
		int day;
		int res;

		year = scan.nextInt();
		month = scan.nextInt();
		day = scan.nextInt();
		res = 0;
		if (isLeap(year))
		{
			res = (month - 1) * 30;
			res += dayueNum[month - 1];
			res += day;
			if (month >= 2)
			{
				res -= 1;
			}
		} else
		{
			res = (month - 1) * 30;
			res += dayueNum[month - 1];
			res += day;
			if (month >= 2)
			{
				res -= 2;
			}
		}
		System.out.println(res);
	}

}


import java.util.*;

public class CompareTwoNumWithReplication
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		String v1 = scan.next();
		int num1 = scan.nextInt();
		String v2 = scan.next();
		int num2 = scan.nextInt();
//		System.out.println(v1 + " " + num1 + " " + v2 + " " + num2);

		if (v1.length() * num1 < v2.length() * num2)
		{
			System.out.println("Less");
			return;
		} else if (v1.length() * num1 > v2.length() * num2)
		{
			System.out.println("Greater");
			return;
		}else
		{
			int temp = Math.max(v1.length(), v2.length());
			int i=0;
			while (i<temp)
			{
				
				if (v1.charAt(i % v1.length()) < v2.charAt(i % v2.length()))
				{
					System.out.println("Less");
					return;
				}else if (v1.charAt(i % v1.length()) > v2.charAt(i % v2.length()))
				{
					System.out.println("Greater");
					return;
				}
				i++;
			}
		}
		System.out.println("Equal");
	}

}

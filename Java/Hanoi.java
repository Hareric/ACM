package ch1;

import java.util.Stack;

public class Hanoi
{


	/**
	 * 使用递归解决汉诺塔问题
	 * 本汉诺塔一次只能移动一格 不能从左直接移动至右
	 * @param n
	 * @param left
	 * @param mid
	 * @param right
	 * @param from
	 * @param to
	 * @return the number of move
	 */
	public static int recurision(int n, String left, String mid, String right, String from, String to)
	{
		if (n == 1)
		{
			if (from.equals(mid) || to.equals(mid))
			{
				System.out.println(from + "-->" + to);
				return 1;
			} else
			{
				System.out.println(from + "-->" + mid);
				System.out.println(mid + "-->" + to);
				return 2;
			}
		} else
		{
			if (from.equals(mid) || to.equals(mid))
			{
				String another = (from.equals(left) || right.equals(left)) ? right : left;
				int phase1 = recurision(n - 1, left, mid, right, from, another);
				int phase2 = recurision(1, left, mid, right, from, to);
				int phase3 = recurision(n - 1, left, mid, right, another, to);
				return phase1 + phase2 + phase3;
			} else
			{
				int phase1 = recurision(n - 1, left, mid, right, from, to);
				int phase2 = recurision(1, left, mid, right, from, mid);
				int phase3 = recurision(n - 1, left, mid, right, to, from);
				int phase4 = recurision(1, left, mid, right, mid, to);
				int phase5 = recurision(n - 1, left, mid, right, from, to);
				return phase1 + phase2 + phase3 + phase4 + phase5;
			}
		}
	}

	public static int hanoi(Stack<Integer> left, Stack<Integer> mid, Stack<Integer> right)
	{
		mid.push(left.pop());
		System.out.println("left --> mid");
		boolean midAndRight = true; // 若为正 则下一步进行的操作是 mid-->right 或者是right-->mid
									// 若为负 则下一步进行的操作是 mid-->left 或者是left-->mid
		int moveNum = 1;
		
		while (!(left.isEmpty() && mid.isEmpty()))
		{
			if(midAndRight)
			{
				if(right.isEmpty())
				{
					right.push(mid.pop());
					System.out.println("mid --> right");
				}
				else if(mid.isEmpty())
				{
					mid.push(right.pop());
					System.out.println("right --> mid");
				}
				else if(mid.peek()<right.peek())
				{
					right.push(mid.pop());
					System.out.println("mid --> right");
				}
				else
				{
					mid.push(right.pop());
					System.out.println("right --> mid");
				}
				midAndRight = false;
				moveNum ++;
			}
			else
			{
				if(left.isEmpty())
				{
					left.push(mid.pop());
					System.out.println("mid --> left");
				}
				else if(mid.isEmpty())
				{
					mid.push(left.pop());
					System.out.println("left --> mid");
				}
				else if(mid.peek()<left.peek())
				{
					left.push(mid.pop());
					System.out.println("mid --> left");
				}
				else
				{
					mid.push(left.pop());
					System.out.println("left --> mid");
				}
				midAndRight = true;
				moveNum ++;
			}
		}
		return moveNum;
		
		
		
		
	}
	public static void main(String[] args)
	{
		int level = 5;
		System.out.println(recurision(level, "left", "mid", "right", "left", "right"));
		System.out.println("********************************************");
		Stack<Integer> s = new Stack<Integer>();
		for(int i=level; i>=1; i--)
		{
			s.push(i);
		}
		System.out.println(hanoi(s, new Stack<Integer>(), new Stack<Integer>()));
		
	}
}

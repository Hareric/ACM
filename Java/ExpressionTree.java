package lintcode;

import java.util.*;

//Definition of ExpressionTreeNode:
class ExpressionTreeNode
{
	public String symbol;
	public ExpressionTreeNode left, right;

	public ExpressionTreeNode(String symbol)
	{
		this.symbol = symbol;
		this.left = this.right = null;
	}
}

public class ExpressionTree
{
	/*
	 * @param expression: A string array
	 * 
	 * @return: 后缀表达式
	 */
	public static LinkedList<String> getRPN(String[] expression)
	{

		// 构建后缀表达式
		LinkedList<String> list1 = new LinkedList<String>();
		LinkedList<String> list2 = new LinkedList<String>();

		for (int i = 0; i < expression.length; i++)
		{
			if (!expression[i].matches("[-()+/*]"))
			{
				list1.addLast(expression[i]);
			} else
			{
				if (expression[i].equals(")"))
				{
					while (true)
					{

						if (list2.peekLast().equals("("))
						{
							list2.pollLast();
							break;
						}
						list1.add(list2.pollLast());
					}
				} else if (list2.isEmpty() || expression[i].equals("(") || list2.peekLast().equals("("))
				{
					list2.addLast(expression[i]);
				} else if (expression[i].matches("[*/]") && list2.peekLast().matches("[+-]"))
				{
					list2.addLast(expression[i]);
				} else
				{
					list1.add(list2.pollLast());
					list2.addLast(expression[i]);
				}
			}
		}
		while (!list2.isEmpty())
		{
			list1.addLast(list2.pollLast());
		}
		return list1;
	}

	public static ExpressionTreeNode build(String[] expression)
	{
		Stack<ExpressionTreeNode> nodeS = new Stack<ExpressionTreeNode>();
		LinkedList<String> RPNlist = getRPN(expression);
		if (RPNlist.isEmpty())
		{
			return null;
		}
		Iterator<String> it = RPNlist.iterator();
		String tmp;
		ExpressionTreeNode nodeTmp;
		while (it.hasNext())
		{
			tmp = it.next();
			nodeTmp = new ExpressionTreeNode(tmp);
			if (!tmp.matches("[-+*/]"))
			{
				nodeS.push(nodeTmp);
			} else
			{
				nodeTmp.right = nodeS.pop();
				nodeTmp.left = nodeS.pop();
				nodeS.push(nodeTmp);
			}
		}
		return nodeS.peek();
	}

	public static void main(String[] args)
	{
		// String[] expression = { "2", "*", "6", "-", "(", "23", "+", "7", ")",
		// "/", "(", "1", "+", "2", ")" };
		String[] expression = { "(", "(", "(", "(", "(", ")", ")", ")", ")", ")" };
		for (String s : getRPN(expression))
		{
			System.out.print(s + " ");
		}
		ExpressionTreeNode node = build(expression);

	}
}

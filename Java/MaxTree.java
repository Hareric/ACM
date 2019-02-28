package ch1;

import java.util.LinkedList;
import java.util.Queue;

class Node
{
	int value;
	public Node left = null;
	public Node right = null;

	public Node(int value)
	{
		this.value = value;
	}
}

public class MaxTree
{

	/**
	 * 深度优先遍历 depth first Travel
	 * 
	 * @param root
	 */
	public static void DFT(Node root)
	{
		if (root == null)
		{
			System.out.print("X" + "  ");
			return;
		}
		System.out.print(root.value + "  ");
		DFT(root.left);
		DFT(root.right);
		// System.out.println("");
	}

	/**
	 * 广度优先遍历 breadth first Travel
	 * 
	 * @param root
	 */
	public static void BFT(Node root)
	{

		Queue<Node> nodeQueue = new LinkedList<Node>();
		;
		nodeQueue.add(root);
		Node levelLastNode = root; // 每一行的最后一个节点
		while (!nodeQueue.isEmpty())
		{
			Node headNode = nodeQueue.poll(); // 队列的第一个节点
			System.out.print(headNode.value + "  ");
			if (headNode == levelLastNode)
			{
				System.out.println(""); // 若该节点为该行最后一节点 则换行
				levelLastNode = null;
			}
			if (headNode.left != null)
			{
				nodeQueue.add(headNode.left);
				if (levelLastNode == null)
				{
					levelLastNode = headNode.left;
				}
			}
			if (headNode.right != null)
			{
				nodeQueue.add(headNode.right);
				if (levelLastNode == null || levelLastNode == headNode.left)
				{
					levelLastNode = headNode.right;
				}
			}
		}
		// System.out.println("");
	}

	public static void createMaxTree(int[] arr)
	{

	}

	public static void main(String[] args)
	{

		Node n1 = new Node(1);
		Node n2 = new Node(2);
		Node n3 = new Node(3);
		Node n4 = new Node(4);
		Node n5 = new Node(5);
		Node n6 = new Node(6);
		Node n7 = new Node(7);
		Node n8 = new Node(8);
		Node n9 = new Node(9);
		Node n10 = new Node(10);
		n1.left = n2;
		n1.right = n3;
		n2.left = n4;
		n2.right = n5;
		n3.left = n6;
		n3.right = n7;
		n4.left = n8;
		n4.right = n9;
		n5.left = n10;
		BFT(n1);

	}
}

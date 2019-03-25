package lintcode;

public class CircularQueue
{
	
	public int[] circularQueue;
	public int head;
	public int rear;
	public int maxSize;
	public int size;
	public CircularQueue(int n)
	{
		// initialize your data structure here
		circularQueue = new int[n];
		head = 0;
		rear = 0;
		size = 0;
		maxSize = n;
		
	}

	/**
	 * @return: return true if the array is full
	 */
	public boolean isFull()
	{
		// write your code here
		if (size == maxSize)
		{
			return true;
		}else
		{
			return false;
		}
	}

	/**
	 * @return: return true if there is no element in the array
	 */
	public boolean isEmpty()
	{
		// write your code here
		if (size == 0)
		{
			return true;
		}else
		{
			return false;
		}
	}

	/**
	 * @param element:
	 *            the element given to be added
	 * @return: nothing
	 */
	public void enqueue(int element)
	{
		// write your code here
		if (isFull())
		{
			return;
		}
		else
		{
			size ++;
			circularQueue[rear] = element;
			rear++;
			rear %= maxSize;
		}
	}

	/**
	 * @return: pop an element from the queue
	 */
	public int dequeue()
	{
		// write your code here
		if (isEmpty())
		{
			return (Integer) null;
		}
		else
		{
			size --;
			int ret = circularQueue[head];
			head ++;
			head %= maxSize;
			return ret;
			
		}
	}
	
	public static void main(String[] args)
	{
		CircularQueue cq = new CircularQueue(5);
		System.out.println(cq.isFull());
		System.out.println(cq.isEmpty());
		cq.enqueue(1);
		cq.enqueue(2);
		System.out.println(cq.dequeue());
	}
}

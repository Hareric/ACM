package lintcode;

import java.util.*;

public class LRUCache
{

	public LinkedList<int[]> mapList;
	public int capacity;
	/*
	 * @param capacity: An integer
	 */public LRUCache(int capacity)
	{
		// do intialization if necessary
		 mapList = new LinkedList<int[]>();
		 this.capacity = capacity;
	}

	/*
	 * @param key: An integer
	 * 
	 * @return: An integer
	 */
	public int get(int key)
	{
		// write your code here
		int[] tmpArr = new int[2];
		for(int[] intArr : mapList)
		{
			if(intArr[0] == key)
			{
				tmpArr[0] = intArr[0];
				tmpArr[1] = intArr[1];
				mapList.remove(intArr);
				mapList.addFirst(tmpArr);
				return tmpArr[1];
			}
			
		}
		return -1;
	}

	/*
	 * @param key: An integer
	 * 
	 * @param value: An integer
	 * 
	 * @return: nothing
	 */
	public void set(int key, int value)
	{
		// write your code here
		int[] tmpArr = new int[2];
		for(int[] intArr : mapList)
		{
			if(intArr[0] == key)
			{
				tmpArr[0] = intArr[0];
				tmpArr[1] = value;
				mapList.remove(intArr);
				mapList.addFirst(tmpArr);
				return;
			}
		}
		if(mapList.size() == capacity)
		{
			mapList.removeLast();
		}
		tmpArr[0] = key;
		tmpArr[1] = value;
		mapList.addFirst(tmpArr);
	}
}

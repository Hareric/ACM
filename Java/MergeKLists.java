/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class MergeKLists {

     
    int[][] arr;
    int arrLength;
    
    public void swap(int i, int j)
	{
		int[] temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		return;
	}
	
	/**
	 * 建立以第l个节点作为根节点的堆
	 * @param l
	 */
	public void adjustHeap(int l)
	{
		for(l=2*l+1; l<arrLength; l=2*l+1)
		{
			
			if(l<arrLength-1&&arr[l][1]>arr[l+1][1])
				l++;
			if(arr[(l-1)/2][1]>arr[l][1])
				swap((l-1)/2, l);
			
		}
	}
	
	public void buildHeap()
	{
		for(int i=arrLength/2-1; i>=0; --i)  // 从i=n/2-1到0，反复调整堆
			adjustHeap(i);
	}
	
    public ListNode mergeKLists(List<ListNode> lists) 
    {  
        // write your code here
        
        while (lists.remove(null));
        this.arrLength = lists.size();
        this.arr = new int[this.arrLength][2];
        
        for (int i=0; i<this.arrLength; i++)
        {
            arr[i][0] = i;
            arr[i][1] = lists.get(i).val;
         
                
        }
        buildHeap();
        ListNode root = null;
        ListNode current = null;
        ListNode tmp;
        while(this.arrLength>0)
        {
            tmp = lists.get(arr[0][0]);
            if(current==null)
            {
                root = tmp;
                current = root;
            }
            else
            {
                current.next = tmp;
                current = current.next;
            }
            
            tmp = tmp.next;
            lists.set(arr[0][0], tmp);
            if(tmp == null)
            {
                this.arrLength--;
                swap(0, this.arrLength);
            }else
            {
                
                arr[0][1] = tmp.val;
            }
            
            adjustHeap(0);
        }
        return root;
    }
}

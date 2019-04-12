public class Solution {
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
     
    public void swap(int[] arr, int locationI, int locationJ)
    {
        int tmp = arr[locationI];
        arr[locationI] =  arr[locationJ];
        arr[locationJ] = tmp;
         
    }
    
    public void adjustHeap(int[] heap, int l, int length)
    {
        if((l+1)*2-1 >= length)
            return;
        int smallerChild;
        if ((l+1)*2 == length)
            smallerChild = (l+1)*2 - 1;
        else if(heap[(l+1)*2-1] < heap[(l+1)*2])
            smallerChild = (l+1)*2-1;
        else
            smallerChild = (l+1)*2;
        if(heap[l]<heap[smallerChild])
            return;
        else
        {
            swap(heap, smallerChild, l);
            adjustHeap(heap, smallerChild, length);
        }
        
    }
    
    public void buildHeap(int[] heap)
    {
        for(int i=heap.length/2-1; i>=0; i--)
        {
            adjustHeap(heap, i, heap.length);
        }
    }
    public int[] topk(int[] nums, int k) 
    {
        // write your code here
        int[] heap = new int[k];
        for(int i=0; i<nums.length; i++)
        {
            if(i<k)
            {
                heap[i] = nums[i];
                if(i==k-1)
                    buildHeap(heap);
                continue;
            }
            if(i==k)
            {
                buildHeap(heap);
            }
            if(nums[i]>heap[0])
            {
                heap[0] = nums[i];
                adjustHeap(heap, 0, k);
            }
        }
        int[] res = new int[k];
        for(int i=k-1; i>=0; i--)
        {
            res[i] = heap[0];
            k--;
            swap(heap, 0, k);
            adjustHeap(heap, 0, k);
        }
        return res;
    }
    
    
}

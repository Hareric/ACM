/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) 
    {
        // write your code here
        int Alength = 0;
        int Blength = 0;
        ListNode n;
        n = headA;
        while(n!= null)
        {
            Alength ++;
            n = n.next;
        }
        n = headB;
        while(n!= null)
        {
            Blength ++;
            n = n.next;
        }
        if(Alength>Blength)
        {
            while(Alength!=Blength)
            {
                headA = headA.next;
                Alength--;
            }
        }else
        {
            while(Alength!=Blength)
            {
                headB = headB.next;
                Blength--;
            }
        }
        while(headA!=null)
        {
            if(headA == headB)
                return headA;
            headA = headA.next;
            headB = headB.next;
        }
        return null;
        
    }
}

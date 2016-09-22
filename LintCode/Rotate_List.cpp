/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        if(head==NULL) return NULL;
        ListNode *cur=head;
        int len=1;
        while(cur->next!=NULL){
            cur=cur->next;
            len++;
        }
        cur->next=head;  
        int preLen = len - k % len - 1;
        ListNode *pre=head;
        while(preLen--)
            pre=pre->next;
        head=pre->next;
        pre->next=NULL;
        return head;

    }
};

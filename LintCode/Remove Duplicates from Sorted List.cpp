/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(head==NULL){
            return NULL;
        }
        ListNode *cur = head;
        ListNode *preCur = head;
        int pre = cur->val;
        cur = cur->next;
        while(true){
            if (cur->val==pre){
                preCur->next = preCur->next->next;
                cur = preCur;
            }
            pre = cur->val;
            preCur = cur;
            if(cur->next==NULL){
                break;
            }
            cur = cur->next;
        }
        return head;
    }
};

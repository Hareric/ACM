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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head==NULL){
            return NULL;
        }
        ListNode *e = new ListNode(-1) ;
        e->next = head;
        head = e;
        ListNode *i = head;
        ListNode *j = NULL;
 

        while(i->next!=NULL){
            if(i->next->val<x){
                if(j!=NULL){
                    ListNode *t = i->next;
                    if (i->next->next == NULL){
                        i->next = NULL;
                        t->next = j->next;
                        j->next = t;
                        break;
                    }
                    else{
                        i->next = i->next->next;
                        t->next = j->next;
                        j->next = t;
                        j = j->next;
                    }
                    continue;
                }
            }
            else{
                if(j==NULL){
                    j = i;
                }
            }
            i = i->next;
        }
        return head->next;
    }
};



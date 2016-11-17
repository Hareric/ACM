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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *result = NULL;
        ListNode *head;
        int jw = 0;
        int sum;
        while(true){
            if(l1==NULL&&l2==NULL){
                if(jw==1){
                    result->next = new ListNode(1);
                }
                break;
            }
            if(l1==NULL){
                sum = l2->val+jw;
                l2 = l2->next;
            }
            else if(l2==NULL){
                sum = l1->val+jw;
                l1 = l1->next;
            }
            else{
                sum = l1->val + l2->val + jw;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            if(sum>9){
                jw=1;
            }
            else{
                jw=0;
            }
            ListNode *temp = new ListNode(sum % 10);
            if(result==NULL){
                result = temp;
                head = temp;
            }
            else{
                result->next = temp;
                result = result->next;
            }
            
           
            
        }
        return head;
    }
};

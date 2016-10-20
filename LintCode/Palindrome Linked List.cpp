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
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (head==NULL){
            return true;
        }
        ListNode *now = head;
        stack <int> s;
        int num = 0;
        while(now!=NULL){
            num++;
            s.push(now->val);
            now = now->next;
        }
        now = head;
        num = (num + 1) / 2;
        while(num--){
            if(now->val!=s.top()){
                return false;
            }
            s.pop();
            now = now->next;
        }
        return true;
    }
};

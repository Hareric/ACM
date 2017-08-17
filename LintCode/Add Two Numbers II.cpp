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
    /*
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        // write your code here
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry=0;
        int times = max(s1.size(), s2.size());
        ListNode *res = new ListNode(0);
        while(!s1.empty()||!s2.empty()){
            int a,b;
            if(!s1.empty()&&!s2.empty()){
                a = s1.top(); s1.pop();
                b = s2.top(); s2.pop();
            }
            else if(s1.empty()){
                a = 0;
                b = s2.top(); s2.pop();
            }
            else{
                a = s1.top(); s1.pop();
                b = 0;
            }
            int temp = a + b + carry;
            if(temp >= 10){
                res->val = temp - 10;
                carry = 1;
            }
            else{
                res->val = temp;
                carry = 0;
            }
            ListNode *head = new ListNode(0);
            head->next = res;
            res = head;
        }
        if (carry==1){
            res->val = 1;
        }
        else{
            res = res->next;
        }
        return res;
        
    }
    
};

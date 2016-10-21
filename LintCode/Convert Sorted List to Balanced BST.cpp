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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *listToTree(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *preSlow = NULL;
        while(fast->next != NULL && fast->next->next != NULL){
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(preSlow){
            preSlow->next = NULL;
        }
        TreeNode *mid = new TreeNode(slow->val);
        if(slow==head){
            mid->left = NULL;
        }
        else{
            mid->left = listToTree(head);
        }
        if(slow->next==NULL){
            mid->right = NULL;
        }
        else{
            mid->right = listToTree(slow->next);
        }
        
        return mid;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(head==NULL){
            return NULL;
        }
        return listToTree(head);
    }
};

/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* ret = NULL;
    void recursion(TreeNode* root, vector<int>& nodeList){
        if (root == NULL){
            return;
        }
        
        recursion(root->left, nodeList);
        nodeList.push_back(root -> val);
        recursion(root->right, nodeList);
    
    }
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        vector<int> nodeList;
        recursion(root, nodeList);
        if (nodeList.size() < 1){
            return NULL;
        }
        DoublyListNode *ret = new DoublyListNode(nodeList[0]);
        DoublyListNode *currentNode = ret;
        for (int i=1; i<nodeList.size(); i++){
            DoublyListNode *temp = new DoublyListNode(nodeList[i]);
            temp -> prev = currentNode;
            currentNode -> next = temp;
            currentNode = temp;
        }
        return ret;
    }
};



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
 */
class Solution {
    
public:
    int maxD = 0;
    void findDepth(TreeNode *root, int nowD){
        nowD++;
        if (nowD>maxD){
            maxD = nowD;
        }
        if(root->left!=NULL){
            findDepth(root->left, nowD);
        }
        if(root->right!=NULL){
            findDepth(root->right, nowD);
        }
    }
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root==NULL){
            return 0;
        }
        findDepth(root, 0);
        return maxD;
    }
};

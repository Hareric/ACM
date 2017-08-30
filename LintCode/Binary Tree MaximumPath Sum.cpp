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
    /*
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int res = -111;
    void bigBackTrack(TreeNode *root){
        int maxLeft = 0;
        int maxRight = 0;
        if (root->left != NULL){
            backTrack(root->left, 0, maxLeft);
        }
        if (root->right != NULL){
            backTrack(root->right, 0, maxRight);
        }
        res = max(res, root->val+maxLeft+maxRight);
        
        if (root->left != NULL){
            bigBackTrack(root->left);
        }
        if (root->right != NULL){
            bigBackTrack(root->right);
        }
    }
    void backTrack(TreeNode *root, int currentValue, int & maxValue){
        currentValue += root->val;
        maxValue = max(maxValue, currentValue);
        if (root->left==NULL&&root->right==NULL){
            return;
        }
        if (root->left != NULL){
            backTrack(root->left, currentValue, maxValue);
        }
        if (root->right != NULL){
            backTrack(root->right, currentValue, maxValue);
        }
        
    }
    int maxPathSum(TreeNode * root) {
        // write your code here
        bigBackTrack(root);
        return res;
    }
};

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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> res;
    
    void recursion(TreeNode * root, int level){
        if (root==NULL){
            return;
        }
        if(res.size()<level+1){
            res.push_back(vector<int>{});
        }
        res[level].push_back(root->val);
        recursion(root->left, level+1);
        recursion(root->right, level+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        recursion(root, 0);
        return res;
        
    }
};

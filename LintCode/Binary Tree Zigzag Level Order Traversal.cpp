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
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */

    void recursion (vector<vector<int>> &ret, int level, TreeNode * root){
        if (root == NULL){
            return ;
        }
        if (level % 2 == 0){
            if (ret.size() < level+1){
                ret.push_back(vector<int>{});
                
                ret[level].push_back(root->val);
            }
            else 
                ret[level].push_back(root->val);
        }
        else{
            if (ret.size() < level+1){
                ret.push_back(vector<int>{});
                ret[level].push_back(root->val);
            }
            else
                ret[level].insert(ret[level].begin(), root->val);
        }
        recursion(ret, level+1, root->left);
        recursion(ret, level+1, root->right);
    }
    vector<vector<int>>  zigzagLevelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> ret;
        recursion(ret, 0, root);
        return ret;
        
    }
};

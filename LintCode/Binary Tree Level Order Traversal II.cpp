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
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> res;
    
    void recursion(TreeNode * root, int level){
        if (root==NULL){
            return;
        }
        if (res.size()<level+1){
            res.push_back(vector<int>{});
        }
        res[level].push_back(root->val);
        if(root->left!=NULL){
            recursion(root->left, level+1);
        }
        if(root->right!=NULL){
            recursion(root->right, level+1);
        }
    }
     
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        // write your code here
        recursion(root, 0);
        vector<vector<int>> ret;
        for(int i=res.size()-1; i>=0; i--){
            ret.push_back(res[i]);
        }
        return ret;
    }
};

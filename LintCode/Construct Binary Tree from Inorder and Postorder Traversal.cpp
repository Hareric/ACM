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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode * recurision(vector<int> &inorder, int inbegin, int inend, vector<int> &postorder, int postbegin, int postend){
        if (inend-inbegin < 0){
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postend]);
        if (inend-inbegin == 1){
            if (postorder[postend] == inorder[inbegin]){
                root->right = new TreeNode(inorder[inend]);
            }else{
                root->left = new TreeNode(inorder[inbegin]);
            }
            return root;
        }
        if (inend-inbegin == 0){
            return root;
        }
        
        int i = 0;
        while (inorder[inbegin+i] != postorder[postend]){
            i++;
        }
        root->left = recurision(inorder, inbegin, inbegin+i-1, postorder, postbegin, postbegin+i-1);
        root->right = recurision(inorder, inbegin+i+1, inend, postorder, postbegin+i, postend-1);
        return root;
    
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.size() < 1){
            return NULL;
        }
        return recurision(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        
    }
};

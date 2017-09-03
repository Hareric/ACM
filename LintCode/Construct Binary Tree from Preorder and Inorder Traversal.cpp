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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:

    TreeNode * recursion(vector<int> &preorder, int preBegin, int preEnd, vector<int> &inorder, int inBegin, int inEnd){
        if (preEnd-preBegin<0){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preBegin]);
        if (preEnd-preBegin==0){
            return root;
        }
        else if (preEnd-preBegin==1){
            if (inorder[inBegin] == preorder[preBegin]){
                root -> right = new TreeNode(preorder[preEnd]);
            }
            else{
                root -> left = new TreeNode(preorder[preEnd]);
            }
            return root;
        }
        int i = 0;
        while(preorder[preBegin]!=inorder[inBegin+i]){
            i++;
        }
        root -> left = recursion(preorder, preBegin+1, preBegin+i, inorder, inBegin, inBegin + i-1);
        root -> right = recursion(preorder, preBegin+1+i, preEnd, inorder, inBegin+i+1, inEnd);
        return root;
    }
    
    
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return recursion(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

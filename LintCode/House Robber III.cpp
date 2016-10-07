/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
     void backTrack(TreeNode* root){
        if (root->left != NULL){
            backTrack(root->left);
        }
        if (root->right != NULL){
            backTrack(root->right);
        }    
        int ll=0, lr=0, rl=0, rr=0, l=0, r=0;
        if(root->left!=NULL){
            l = root->left->val;
            if(root->left->right!=NULL){
                lr = root->left->right->val;
            }
            if(root->left->left!=NULL){
                ll = root->left->left->val;
            }
        }
        if(root->right!=NULL){
            r = root->right->val;
            if(root->right->right!=NULL){
                rr = root->right->right->val;
            }
            if(root->right->left!=NULL){
                rl = root->right->left->val;
            }
        }
        root->val = max(ll+rr+lr+rl+root->val, l+r);
     }
    int houseRobber3(TreeNode* root) {
        // write your code here
        if (root == NULL){
            return 0;
        }
        backTrack(root);
        return root->val;

        
    }
};

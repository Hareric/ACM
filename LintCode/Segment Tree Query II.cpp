/** 
 * Definition of SegmentTreeNode: 
 * class SegmentTreeNode { 
 * public: 
 *     int start, end, count; 
 *     SegmentTreeNode *left, *right; 
 *     SegmentTreeNode(int start, int end, int count) { 
 *         this->start = start; 
 *         this->end = end; 
 *         this->count = count; 
 *         this->left = this->right = NULL; 
 *     } 
 * } 
 */  
class Solution {  
public:  
    /** 
     *@param root, start, end: The root of segment tree and  
     *                         an segment / interval 
     *@return: The count number in the interval [start, end]  
     */  
    int query(SegmentTreeNode *root, int start, int end) {  
        // write your code here  
        if (root == NULL || start > root->end)  
        {  
            return 0;  
        }  
        if (start <= root->start && end >= root->end)  
        {  
            return root->count;  
        }  
        else if (start >= root->left->start && start <= root->left->end)  
        {  
            if (end <= root->left->end)  
            {  
                return query(root->left, start, end);  
            }  
            else  
            {  
                return query(root->left, start, root->left->end)   
                            + query(root->right, root->right->start,   
                                    min(end, root->right->end));  
            }  
        }  
        else  
        {  
            return query(root->right, start, min(end, root->right->end));  
        }  
    }  
};  

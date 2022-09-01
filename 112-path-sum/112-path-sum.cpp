/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


/*
Acutually the question is asking you to start from root node and move till leaf node( a node which has no left and no right child as on line 26 in code )
when you reach at leaf node check that whether the sum you have calculated on this path is equal to the current sum or not.
*/


class Solution {
public:
    bool dfs(TreeNode* node, int final_sum) {
        if(not node) {
            return false;
        }
        final_sum-=node->val;
        if(not node->left and not node->right) {
            if(final_sum==0) {
                return true;
            }
            return false;
        }
        return dfs(node->left,final_sum) or dfs(node->right,final_sum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }
};
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
class Solution {
public:
    bool dfs(TreeNode* node, int curr_sum, int target) {
        if(not node) {
            return false;
        }
        curr_sum+=node->val;
        if(not node->left and not node->right) {
            if(curr_sum==target) {
                return true;
            }
            return false;
        }
        return dfs(node->left,curr_sum,target) or dfs(node->right,curr_sum,target);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }
};
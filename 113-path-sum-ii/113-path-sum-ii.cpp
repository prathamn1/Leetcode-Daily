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
    void dfs(TreeNode* node,int curr_sum,vector<int>curr_path,vector<vector<int>>&ans) {
        if(not node) {
            return;
        }
        curr_sum-=node->val;
        curr_path.push_back(node->val);
        if(not node->left and not node->right) {
            if(curr_sum==0) {
                ans.push_back(curr_path);
            }
        }
        dfs(node->left,curr_sum,curr_path,ans);
        dfs(node->right,curr_sum,curr_path,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        dfs(root,targetSum,vector<int>(),ans);
        return ans;
    }
};
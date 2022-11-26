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
    void solve(TreeNode* root,string curr_path,vector<string>&ans) {
        if(not root) {
            return ;
        }
        if(not root->left and not root->right) {
            curr_path+=to_string(root->val);
            ans.emplace_back(curr_path);
        }else {
            curr_path+=to_string(root->val)+"->";
        }
        solve(root->left,curr_path,ans);
        solve(root->right,curr_path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        solve(root,"",ans);
        return ans;
    }
};
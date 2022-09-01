/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<int>&curr_path,vector<string>&ans) {
        if(not root){
            return ;
        }
        curr_path.push_back(root->val);
        if(not root->left and not root->right) {
            ans.push_back(to_string(curr_path[0]));
            for(int i=1;i<curr_path.size();i++) {
                ans.back()+="->"+to_string(curr_path[i]);
            }
        }
        dfs(root->left,curr_path,ans);
        dfs(root->right,curr_path,ans);
        curr_path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>curr_path;
        vector<string>ans;
        dfs(root,curr_path,ans);
        return ans;
    }
};
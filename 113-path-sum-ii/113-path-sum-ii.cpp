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
*/

/*
class Solution {
public:
    void dfs(TreeNode* node,int curr_sum,vector<int>&curr_path,vector<vector<int>>&ans) {
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
        curr_path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr_path;
        dfs(root,targetSum,curr_path,ans);
        return ans;
    }
};
*/

//we can also implement in a way like when we call dfs we subtract value there and there only and while checking for the valid sum we check in a way like -- suppose we are standing on node x , then we will check that is the curr_sum value is node x->val and also that the node x is leaf node.

//Actually what i was doing in the above two solutions that first I was adding current node value to the curr_sum and then checking if it is the leaf node and curr_sum==0 ,but here in below solution i am first adding the current_node value to my current_path and then checking that if my curr_sum==current_node->val and then when i am calling dfs i am subtracting current node value for the next node
class Solution {
public:
    void dfs(TreeNode* node,int curr_sum,vector<int>&curr_path,vector<vector<int>>&ans) {
        if(not node) {
            return;
        }
        curr_path.push_back(node->val);
        if(not node->left and not node->right and curr_sum==node->val) {
            ans.push_back(curr_path);
        }
        dfs(node->left,curr_sum-node->val,curr_path,ans);
        dfs(node->right,curr_sum-node->val,curr_path,ans);
        curr_path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr_path;
        dfs(root,targetSum,curr_path,ans);
        return ans;
    }
};


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
    int ans=0;
    void dfs(TreeNode* node,long long int curr_sum,unordered_map<long long int,long long int>&mp,int target_sum) {
        if(not node) {
            return ;
        }
        curr_sum+=node->val;
        if(mp.find(curr_sum-target_sum)!=mp.end()) {
            ans+=mp[curr_sum-target_sum];
        }
        mp[curr_sum]++;
        dfs(node->left,curr_sum,mp,target_sum);
        dfs(node->right,curr_sum,mp,target_sum);
        mp[curr_sum]--;
        curr_sum-=node->val;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int,long long int>mp;
        mp.insert({0,1});
        dfs(root,(long long int )0,mp,targetSum);
        return ans;
    }
};
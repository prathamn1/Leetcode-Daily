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
    string solve(TreeNode* root,vector<TreeNode *> &ans, string &s,unordered_map<string,int>&mp) {
        if(not root) {
            return "";
        }
        //just make recursion tree and remember when the call goes for 4->left ie null then the function returns "" to the previous call that is when the root will be 4 and then the string will be ( after that root->val will be added so string will be (4 then again call goes for 4->right so it will return empty string and then finally a ) will be added so final string will be (4) and it will be added to the map and then the s will be returned as (4) to the previous call when the root will be 2 and so on.
        // just make recursion tree.
        s="("+solve(root->left,ans,s,mp)+to_string(root->val)+solve(root->right,ans,s,mp)+")";
        cout<<s<<"  ";
        mp[s]++;
        if(mp[s]==2) {
            ans.push_back(root);
        }
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        string s;
        unordered_map<string,int>mp;
        solve(root,ans,s,mp);
        return ans;
        
    }
};
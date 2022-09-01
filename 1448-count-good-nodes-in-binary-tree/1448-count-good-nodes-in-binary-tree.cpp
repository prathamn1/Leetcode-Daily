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

//Thought process will be in a way like to start with root node with the maximum value to be minimum integer value possible ie INT_MIN and then do depth-first-search for every node and update the maxi value covered so far on that path .

//All in one don't think too much dfs will take care of everything
class Solution {
public:
    void dfs(TreeNode* node,int maxi,int &ans) {
        if(not node) {
            return ;
        }
        if(node->val>=maxi) {
            ans+=1;
            maxi=node->val;
        }
        dfs(node->left,maxi,ans);
        dfs(node->right,maxi,ans);    
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,INT_MIN,ans);
        return ans;
    }
};
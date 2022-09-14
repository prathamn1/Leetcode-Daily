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
    bool check_palindromic(vector<int>& freq) {
        int odd=0;
        for(int i=1;i<10;i++) {
            if(freq[i]%2!=0) {
                odd+=1;
            }
        }
        if(odd>1) {
            return false;
        }
        return true;
    }
    
    void dfs(TreeNode* root,vector<int>freq,int & ans) {
        if(not root) {
            return;
        }
        freq[root->val]++;
        if(not root->left and not root->right) {
            if(check_palindromic(freq)) {
                ans++;
            }
            // freq[root->val]--;
            return ;
        }
        dfs(root->left,freq,ans);
        
        dfs(root->right,freq,ans);
        // freq[root->val]--;
    }
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10,0);
        int ans=0;
        dfs(root,freq,ans);
        return ans;
    }
};
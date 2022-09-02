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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if( not root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()) {
            ans.push_back(vector<int>());
            int st=q.size();
            for(int i=0;i<st;i++) {
                TreeNode* k=q.front();
                ans.back().push_back(k->val);
                q.pop();
                if(k->left) {
                    q.push(k->left);
                }
                if(k->right) {
                    q.push(k->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
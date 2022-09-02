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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()) {
            double s=0;
            int st=q.size();
            for(int i=0;i<st;i++) {
                TreeNode* k=q.front();
                s+=k->val;
                q.pop();
                if(k->left) {
                    q.push(k->left);
                }
                if(k->right) {
                    q.push(k->right);
                }
            }
            ans.push_back(s/st); 
        }
        return ans;
    }
};
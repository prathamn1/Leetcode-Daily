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


//iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        st.push(root);
        while(not st.empty()) {
            TreeNode* k=st.top();
            if(not k) {
                break;
            }
            ans.push_back(k->val);
            st.pop();
            if(k->right) {
                st.push(k->right);
            }
            if(k->left) {
                st.push(k->left);
            }
        }
        return ans;
    }
};
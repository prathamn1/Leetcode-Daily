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
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        while(not st.empty()) {
            TreeNode* k=st.top();
            st.pop();
            if(k and k->right)
            st.push(k->right);
            if(k and k->left)
            st.push(k->left);
            if(not st.empty()) {
                TreeNode* l=st.top();
                k->right=l;
                k->left=NULL;
            }
        }
    }
};
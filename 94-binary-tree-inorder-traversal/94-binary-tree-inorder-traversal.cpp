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
// class Solution {
// public:
    
//     vector<int>ans;
//     void solve(TreeNode* root,vector<int>&ans) {
//         if(not root) {
//             return ;
//         }
//         solve(root->left,ans);
//         ans.push_back(root->val);
//         solve(root->right,ans);
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         solve(root,ans);
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         stack<TreeNode*>st;
//         st.push(root);
//         while(not st.empty()) {
//             TreeNode* k = st.top();
//             if(not k) {
//                 st.pop();
//                 if(not st.empty()) {
//                     k=st.top();
//                     ans.push_back(k->val);
//                     st.pop();
//                     st.push(k->right);
//                 }
//             }else {
//                 st.push(k->left);
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* node=root;
        stack<TreeNode*>st;
        while(true) {
            if(node) {
                st.push(node);
                node=node->left;
            }else {
                if(st.empty()) {
                    break;
                }
                ans.push_back(st.top()->val);
                node=st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};
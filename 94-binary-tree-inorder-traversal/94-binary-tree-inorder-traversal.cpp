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





// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         TreeNode* node=root;
//         stack<TreeNode*>st;
//         while(true) {
//             if(node) {
//                 st.push(node);
//                 node=node->left;
//             }else {
//                 if(st.empty()) {
//                     break;
//                 }
//                 ans.push_back(st.top()->val);
//                 node=st.top()->right;
//                 st.pop();
//             }
//         }
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

//All three traversal using one stack


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(not root) {
            return vector<int>();
        }
        
        
        vector<int>preorder;   //id=1
        vector<int>inorder;//id=2
        vector<int>postorder;//id=3
        
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(not st.empty()) {
            pair<TreeNode*,int>k=st.top();
            st.pop();
            if(k.second==1) {
                preorder.push_back(k.first->val);
                k.second++;
                st.push(k);
                if(k.first->left) {
                    st.push({k.first->left,1});
                }
            }
            
            else if(k.second==2) {
                inorder.push_back(k.first->val);
                k.second++;
                st.push(k);
                if(k.first->right) {
                    st.push({k.first->right,1});
                }
            }
            else {
                postorder.push_back(k.first->val);
            }
        }
        return inorder;   
    }
};


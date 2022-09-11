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


//use two stacks

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(not st1.empty()) {
            TreeNode* k =st1.top();
            if(not k) {   // to remove this block just use if(not root) return NULL at beginning
                break;
            }
            st1.pop();
            
            st2.push(k);
            if(k->left) {
                st1.push(k->left);
            }
            if(k->right) {
                st1.push(k->right);
            }
        }
        while(not st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
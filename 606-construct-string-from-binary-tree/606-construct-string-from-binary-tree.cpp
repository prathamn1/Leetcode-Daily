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
    void preorder(TreeNode* root ,string &s) {
        s+=to_string(root->val);
        if(not root->left and root->right) {
            s+="()";
        }
        if(root->left) {
            s+="(";
            preorder(root->left,s);
            s+=")";
        }
        if(root->right){
            s+="(";
            preorder(root->right,s);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string ans;
        preorder(root,ans);
        return ans;
    }
};
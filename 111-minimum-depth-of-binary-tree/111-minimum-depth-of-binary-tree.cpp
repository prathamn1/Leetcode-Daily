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
    int minDepth(TreeNode* root) {
        if(not root) {
            return 0;
        }
        queue<TreeNode*>q;
        int mini_depth=0;
        q.push(root);
        bool leaf_found=false;
        while(not q.empty() and not leaf_found) {
            int st=q.size();
            for(int i=0;i<st;i++) {
                TreeNode*k=q.front();
                q.pop();
                if(not k->left and not k->right) {
                    leaf_found=true;
                    break;
                }else {
                    if(k->left) {
                        q.push(k->left);
                    }
                    if(k->right) {
                        q.push(k->right);
                    }
                }
            }
            mini_depth+=1;
        }
        return mini_depth;
    }
};
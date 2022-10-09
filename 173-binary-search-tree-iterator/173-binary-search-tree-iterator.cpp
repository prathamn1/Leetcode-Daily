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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        insert_left(root->left,st);
    }
    void insert_left(TreeNode* node,stack<TreeNode*>&st) {
        if(node) {
            st.push(node);
            insert_left(node->left,st);
        }
    }
    int next() {
        int ret;
        if(not st.empty()) {
            TreeNode * k=st.top();
            ret=k->val;
            st.pop();
            insert_left(k->right,st);
        }
        return ret;
    }
    
    bool hasNext() {
        if(not st.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
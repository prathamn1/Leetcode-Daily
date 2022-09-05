/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        vector<vector<int>>ans;
        q.push(root);
        if(not root) {
            return ans;
        }
        while(not q.empty()) {
            int st=q.size();
            ans.push_back(vector<int>());
            for(int i=0;i<st;i++) {
                Node* k=q.front();
                q.pop();
                if(k) {
                    ans.back().push_back(k->val);
                    for(int j=0;j<k->children.size();j++) {
                        q.push(k->children[j]);
                    }
                }
                
            }
        }
        return ans;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(not root) {
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(not q.empty()) {
            int st=q.size();
            Node* k;
            for(int i=0;i<st;i++) {
                k=q.front();
                q.pop();
                if(k->left) {
                    q.push(k->left);
                }
                if(k->right) {
                    q.push(k->right);
                }
                
                if(q.empty()) {
                    k->next=NULL;
                }else {
                    k->next=q.front();
                }
            }
            k->next=NULL;
        }
        return root;
    }
};
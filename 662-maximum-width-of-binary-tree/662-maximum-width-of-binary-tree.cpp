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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int level=0;
        while(!q.empty())
        {
            int first,last;
            int sz=q.size();
            int min=q.front().second;
            
            // cout<<"Level is: "<<level+1<<endl;
            for(int i=0;i<sz;i++)
            {
                int curr_idx=q.front().second-min;
                TreeNode*curr=q.front().first;
                q.pop();
                if(i==0) first=curr_idx;
                if(i==sz-1) last=curr_idx;
                
                if(curr->left)
                    q.push({curr->left,2LL*curr_idx+1});
                if(curr->right)
                    q.push({curr->right,2LL*curr_idx+2});
            }
            // cout<<first<<" "<<last<<endl;
            // level++;
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
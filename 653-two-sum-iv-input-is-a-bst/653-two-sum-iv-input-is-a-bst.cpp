class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>st1,st2;
        TreeNode*root1=root,*root2=root;
        while(true){
            while(root1){
                st1.push(root1);
                root1=root1->left;
            }
            while(root2){
                st2.push(root2);
                root2=root2->right;
            }
            
            root1=st1.top(); 
            root2=st2.top();
            
            // equivalent to left pointer >= right pointer return false in two sum apporach in a vector
            if(root1==root2) return false;
            
            int sum=root1->val+root2->val;
            if(root1!=root2 and sum==k)return true;
            
            if(sum<k){
                st1.pop();
                root1=root1->right;
                root2=NULL;
            }
            else{
                st2.pop();
                root2=root2->left;
                root1=NULL;
            }  
        }
        return false;
    }
};

// TIME COMPLEXITY => O(N) 
// SPACE COMPLEXITY => O(H)
// N => total number of nodes 
// H => height of bst O(logN)
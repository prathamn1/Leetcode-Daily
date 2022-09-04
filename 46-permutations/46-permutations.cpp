class Solution {
public:
    void solve(int n,vector<int>nums,vector<int>&curr_perm,vector<bool>&visited,vector<vector<int>>&ans) {
        if(curr_perm.size()==n) {
            ans.push_back(curr_perm);
        }
        int i=0;
        while(i<n) {
            if(not visited[i]) {
                curr_perm.push_back(nums[i]);
                visited[i]=true;
                solve(n,nums,curr_perm,visited,ans);
                curr_perm.pop_back();
                visited[i]=false;
            }
            i++;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr_perm;
        vector<bool>visited(n,false);
        solve(n,nums,curr_perm,visited,ans);
        return ans;
    }
};
class Solution {
public:
    int solve(int curr_index,vector<int>&nums,int n,vector<int>&dp) {
        if(curr_index>=n-1) {
            return 0;
        }
        if(dp[curr_index]!=-1) {
            return dp[curr_index];
        }
        int mini=100000;
        for(int i=curr_index+1;i<=min(n-1,curr_index+nums[curr_index]);i++) {
            mini=min(mini,1+solve(i,nums,n,dp));
        }
        return dp[curr_index]=mini;
    }
    
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,nums.size(),dp);
    }
};
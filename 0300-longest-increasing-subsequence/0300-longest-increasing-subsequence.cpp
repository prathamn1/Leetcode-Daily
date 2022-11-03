class Solution {
public:
    int solve(int curr_index,int prev_index,int n,vector<int>&nums,vector<vector<int>>&dp) {
        if(curr_index==n) {
            return 0;
        }
        if(dp[prev_index+1][curr_index]!=-1) {
            return dp[prev_index+1][curr_index];
        }
        int take=0;
        if(prev_index==-1 or nums[curr_index]>nums[prev_index]) {
            take=1+solve(curr_index+1,curr_index,n,nums,dp);
        }
        int not_take=0+solve(curr_index+1,prev_index,n,nums,dp);
        return dp[prev_index+1][curr_index]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};
class Solution {
public:
    int solve(int prev_house,int curr_house,int& n,vector<int>& nums,vector<vector<int>>&dp) {
        if(curr_house==n) {
            return 0;
        }
        if(dp[curr_house][prev_house+2]!=-1) {
            return dp[curr_house][prev_house+2];
        }
        int not_rob=solve(prev_house,curr_house+1,n,nums,dp);
        int rob=0;
        if(curr_house-prev_house>1) {
            rob=nums[curr_house]+solve(curr_house,curr_house+1,n,nums,dp);
        }
        return dp[curr_house][prev_house+2]= max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+2,-1));
        return solve(-2,0,n,nums,dp);
    }
};
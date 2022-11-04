// first write the recurrence tree then write the code and then memoize it.
// remember to use prev_index in recursion instead of prev_element as prev_element can be negative and thereby increasing dp size to double its range will throw memory limit exceedec.
//
// class Solution {
// public:
//     int solve(int curr_index,int prev_index,int n,vector<int>&nums,vector<vector<int>>&dp) {
//         if(curr_index==n) {
//             return 0;
//         }
//         if(dp[prev_index+1][curr_index]!=-1) {//adding 1 to prev_index as prev_index is -1 so to avoid any error we have made dp of size(n+1,n+1)
//             return dp[prev_index+1][curr_index];
//         }
//         int take=0;
//         if(prev_index==-1 or nums[curr_index]>nums[prev_index]) {
//             take=1+solve(curr_index+1,curr_index,n,nums,dp);
//         }
//         int not_take=0+solve(curr_index+1,prev_index,n,nums,dp);
//         return dp[prev_index+1][curr_index]=max(take,not_take);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(0,-1,n,nums,dp);
//     }
// };



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(nums[i]>nums[j] and dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};
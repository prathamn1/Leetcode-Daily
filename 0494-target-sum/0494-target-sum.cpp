class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),total_sum=accumulate(nums.begin(),nums.end(),0);
        if((total_sum+target<0) or (total_sum+target)%2!=0) {
            return 0;
        }else {
            target=(total_sum+target)/2;
        }
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=target;j++) {
                if(j==0) {
                    dp[i][j]=1;
                }
                if(j-nums[i-1]<0) {
                    dp[i][j]=dp[i-1][j];
                }else {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};
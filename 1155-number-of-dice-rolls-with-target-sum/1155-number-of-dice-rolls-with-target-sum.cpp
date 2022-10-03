class Solution {
public:
    long long solve(int curr_dice,int faces,int curr_target,vector<vector<int>>&dp) {
        if(curr_target<0) {
            return 0;
        }
        if(curr_dice==0) {
            if(curr_target==0) {
                return 1;
            }else {
                return 0;
            }
        }
        long long ct=0;
        if(dp[curr_dice][curr_target]!=-1) {
            return dp[curr_dice][curr_target];
        }
        for(int i=1;i<=faces;i++) {
            ct+=solve(curr_dice-1,faces,curr_target-i,dp);
        }
        return dp[curr_dice][curr_target]=ct%(1000000007);   
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        long long ans=0;
        return solve(n,k,target,dp)%(1000000007);
        
    }
};
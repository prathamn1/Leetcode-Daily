class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>>dp(n+1,vector<long long>(amount+1));
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=amount;j++) {
                if(j==0) {
                    dp[i][j]=0;
                }else if(i==0) {
                    dp[i][j]=INT_MAX;
                }else if(j<coins[i-1]) {
                    dp[i][j]=dp[i-1][j];
                }else {
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount]!=INT_MAX ? dp[n][amount]:-1;
   }
};
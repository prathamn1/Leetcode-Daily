//make a dp table in which rows are amount +1 and columns are n+1 now to fill that
//for the 0th row first - we know that without any coins we could not sum to any money except zero so fill every col(except 0th) with infinity and fill zero th col completely with 0 as for amount =0 we need zero coins.
// now if amount we needed to make(j th index) is less than the current coin we have the (coin[i-1]) so we will exclude that coin which means that we will take the value of dp[i-1][j] and if the value is greater than we will take the minimum(excluding the current coin (dp[i-1][j]) , including the current coin 1+dp[i][j-coins[i-1]],note we are adding one as we are taking that coin so the num_coin has to be increased and we are checking in the same row as we can take the same coin more than once)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1));
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=amount;j++) {
                if(j==0) {
                    dp[i][j]=0;
                }else if(i==0) {
                    dp[i][j]=1e5;
                }else if(j<coins[i-1]) {
                    dp[i][j]=dp[i-1][j];
                }else {
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount]!=1e5 ? dp[n][amount]:-1;
   }
};
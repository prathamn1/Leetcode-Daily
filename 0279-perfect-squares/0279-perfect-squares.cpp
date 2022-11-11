class Solution {
public:
    int numSquares(int target) {
        vector<int> squares;
        for(int i=1;i*i<=target;i++) {
            squares.emplace_back(i*i);
        }
        int len=squares.size();
        vector<vector<int>>dp(len+1,vector<int>(target+1));
        for(int i=0;i<=len;i++) {
            for(int j=0;j<=target;j++) {
                if(j==0) {
                    dp[i][j]=0;
                }else if(i==0) {
                    dp[i][j]=100000;
                }else if(j<squares[i-1]) {
                    dp[i][j]=dp[i-1][j];
                }else {
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-squares[i-1]]);
                }
            }
        }
        return dp[len][target];
    }
};
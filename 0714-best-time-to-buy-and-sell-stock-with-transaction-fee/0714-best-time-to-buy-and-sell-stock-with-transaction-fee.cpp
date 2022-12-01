class Solution {
public:
    //state : 0 -> buy , 1->sell
    int solve(int curr_day,int n, vector<int>& prices,int fee,int state,vector<vector<int>>& dp) {
        if(curr_day>=n) {
            return 0;
        }
        if(dp[curr_day][state]!=-1) {
            return dp[curr_day][state];
        }
        int do_nothing=solve(curr_day+1,n,prices,fee,state,dp);
        int buy_sell;
        if(state==0) {
            buy_sell=-prices[curr_day]+solve(curr_day+1,n,prices,fee,1-state,dp);
        }else {
            buy_sell=prices[curr_day]-fee+solve(curr_day+1,n,prices,fee,1-state,dp);
        }
        return dp[curr_day][state]=max(do_nothing,buy_sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices.size(),prices,fee,0,dp);
    }
};
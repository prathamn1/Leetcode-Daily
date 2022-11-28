class Solution {
public:
    //buy=0 ; sell =1;
    
    int solve(vector<int>&prices,int curr_index,int& n,int state,vector<vector<int>>& dp) {
        if(curr_index>=n) {
            return 0;
        }
        if(dp[curr_index][state]!=-1) {
            return dp[curr_index][state];
        }
        int ans1=solve(prices,curr_index+1,n,state,dp);
        int ans2;
        
        if(state==0) {
            ans2= -prices[curr_index]+solve(prices,curr_index+1,n,1,dp);
        }else {
            ans2=prices[curr_index]+solve(prices,curr_index+2,n,0,dp);
        }
        return dp[curr_index][state]=max(ans1,ans2);
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,n,0,dp);
    }
};
class Solution {
public:
    long long mod=1000000007;
    int solve(int curr_pos,int end_pos,int steps_left,vector<vector<int>>&dp) {
        if(curr_pos==end_pos and steps_left==0) {
            return 1;
        }
        if(steps_left==0) {
            return 0;
        }
        if(dp[curr_pos+1000][steps_left]!=-1) {
            return dp[curr_pos+1000][steps_left];
        }
        return dp[curr_pos+1000][steps_left]=(solve(curr_pos+1,end_pos,steps_left-1,dp)+solve(curr_pos-1,end_pos,steps_left-1,dp))%mod;
    }
    
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3001,vector<int>(k+1,-1));//to include negative ranges values we have taken rows upto 20001 
        return solve(startPos,endPos,k,dp)%mod;
    }
};
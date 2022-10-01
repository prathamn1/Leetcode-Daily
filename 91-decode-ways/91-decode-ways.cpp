class Solution {
public:
    int solve(int curr_index,int n, string s, vector<int>&dp) {
        if(curr_index>n) {
            return 0;
        }else if(curr_index==n) {
            return 1;
        }else if(s[curr_index]=='0') {
            return 0;
        }else if(dp[curr_index]!=-1) {
            return dp[curr_index];
        }else if(s[curr_index]=='1' or (s[curr_index]=='2' and (s[curr_index+1]>='0' and s[curr_index+1]<='6'))) {
            return dp[curr_index]=solve(curr_index+1,n,s,dp)+solve(curr_index+2,n,s,dp);
        }else {
            return dp[curr_index]=solve(curr_index+1,n,s,dp);
        }
    }
    
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp (n,-1);
        return solve(0,n,s,dp);
    }
};
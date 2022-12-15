class Solution {
public:
    int solve(int curr_index1,int curr_index2,int m,int n,string &text1,string &text2,vector<vector<int>>&dp) {
        if(curr_index1==m or curr_index2==n) {
            return 0;
        }
        if(dp[curr_index1][curr_index2]!=-1) {
            return dp[curr_index1][curr_index2];
        }
        if(text1[curr_index1]==text2[curr_index2]) {
            return dp[curr_index1][curr_index2]=1+solve(curr_index1+1,curr_index2+1,m,n,text1,text2,dp);
        }
        return dp[curr_index1][curr_index2]=max(solve(curr_index1+1,curr_index2,m,n,text1,text2,dp),solve(curr_index1,curr_index2+1,m,n,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,text1,text2,dp);
    }
};
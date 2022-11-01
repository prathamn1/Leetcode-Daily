class Solution {
public:
    // int solve(int curr_row,int curr_col,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&grid) {
    int solve(int curr_row,int curr_col,int m,int n,int dp[100][100],vector<vector<int>>&grid) {

        if(curr_row==m) {
            return curr_col;
        }
        if(dp[curr_row][curr_col]!=0) {
            return dp[curr_row][curr_col];
        }
        if(curr_col+1<n and grid[curr_row][curr_col]==1 and grid[curr_row][curr_col+1]==1) {
            return dp[curr_row][curr_col]=solve(curr_row+1,curr_col+1,m,n,dp,grid);
        }
        else if(curr_col-1>=0 and grid[curr_row][curr_col]==-1 and grid[curr_row][curr_col-1]==-1) {
            return dp[curr_row][curr_col]=solve(curr_row+1,curr_col-1,m,n,dp,grid);
        }else {
            return -1;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans;
        // vector<vector<int>>dp(m,vector<int>(n,0));
        int dp[100][100];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) {
            ans.push_back(solve(0,i,m,n,dp,grid));
        }
        return ans;
    }
};
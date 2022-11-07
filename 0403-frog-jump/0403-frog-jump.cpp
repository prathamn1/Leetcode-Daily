class Solution {
public:
    
    int solve(int prev_stone,int curr_stone,int n,unordered_map<int,int>&stone_pos,vector<vector<int>>&dp) {
        if(curr_stone==prev_stone or stone_pos.find(curr_stone)==stone_pos.end()) {
            return 0;
        }
        if(stone_pos[curr_stone]==n-1) {
            return 1;
        }
        if(dp[stone_pos[curr_stone]][stone_pos[prev_stone]]!=-1) {
            return dp[stone_pos[curr_stone]][stone_pos[prev_stone]];
        }
        int jump=curr_stone-prev_stone;
        return dp[stone_pos[curr_stone]][stone_pos[prev_stone]] = solve(curr_stone,curr_stone+jump-1,n,stone_pos,dp) or solve(curr_stone,curr_stone+jump,n,stone_pos,dp) or solve(curr_stone,curr_stone+jump+1,n,stone_pos,dp); 
    }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int>stone_pos;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) {
            stone_pos[stones[i]]=i;
        }
        if(stones[1]!=1){
            return false;
        }
        return solve(0,1,n,stone_pos,dp);
    }
};
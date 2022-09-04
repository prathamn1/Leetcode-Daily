class Solution {
public:
    void solve(int n,vector<int>&curr_perm,unordered_map<int,int>&visited,vector<vector<int>>&ans) {
        if(curr_perm.size()==n) {
            ans.push_back(curr_perm);
        }
        for(auto &i:visited) {
            if(i.second) {
                curr_perm.push_back(i.first);
                i.second--;
                solve(n,curr_perm,visited,ans);
                curr_perm.pop_back();
                i.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr_perm;
        unordered_map<int,int>visited;
        for(auto i:nums) {
            visited[i]++;
        }
        solve(n,curr_perm,visited,ans);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back({});
        for(auto i:nums) {
            int length=ans.size();
            for(int j=0;j<length;j++) {
                vector<int>temp=ans[j];
                temp.push_back(i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
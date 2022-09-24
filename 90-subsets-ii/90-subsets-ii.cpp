class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<multiset<int>>ans;
        int total_subsets=1<<nums.size();
        for(int i=0;i<total_subsets;i++) {
            multiset<int>temp;
            for(int j=0;j<nums.size();j++) {
                if(((i>>j)&1)==1) {
                    temp.insert(nums[j]);
                }
            }
            ans.insert(temp);
        }
        vector<vector<int>>a;
        for(auto i:ans) {
            a.push_back({});
            for(auto j:i) {
                a.back().push_back(j);
            }
        }
        return a;
    }
};
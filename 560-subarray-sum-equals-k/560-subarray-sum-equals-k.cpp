class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix_sum_map;
        prefix_sum_map[0]=1;
        int pre=0,ans=0;
        for(auto i:nums) {
            if(prefix_sum_map.find(pre+i-k)!=prefix_sum_map.end()) {
                ans+=prefix_sum_map[pre+i-k];
            }
            pre+=i;
            prefix_sum_map[pre]++;
        }
        return ans;
    }
};
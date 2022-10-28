class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int pre_sum=0,ans=0;
        unordered_map<int,int>prefix_sum;
        prefix_sum[0]=1;
        for(auto i:nums) {
            pre_sum+=i;
            if(prefix_sum.find(pre_sum-goal)!=prefix_sum.end()) {
                ans+=prefix_sum[pre_sum-goal];
            }
            prefix_sum[pre_sum]++;
        }  
        return ans;
    }
};
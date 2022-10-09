class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        int ans=0;
        unordered_map<long long,long long>mp;
        for(auto i:nums3) {
            for(auto j :nums4) {
                mp[i+j]++;
            }
        }
        // for(auto [i,j]:mp) {
        //     cout<<i<<" "<<j<<endl;
        // }
        for(auto i:nums1) {
            for(auto j:nums2) {
                long long sum=(long long)i +(long long)j;
                
                ans+=mp[0-sum];
                // cout<<i<<"  "<<j<<"  : "<<ans<<endl;
            }
        }
        return ans;
    }
};
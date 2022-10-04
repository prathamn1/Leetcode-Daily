class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(k-nums[i])!=mp.end() and mp[k-nums[i]]>0) {
                ans+=1;
                mp[k-nums[i]]-=1;
            }else {
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};
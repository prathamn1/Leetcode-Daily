class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size(),ans=0;
        
//         unordered_map<string,int>mp;
//         for(auto i:nums) {
//             mp[i]++;
//         }
//         vector<pair<string,string>>pre_suff;
//         string pre="",suff="";
//         for(int i=0;i<n;i++) {
//             pre+=target[i];
//             suff=target[n-i-1]+suff;
//             pre_suff.push_back({pre,suff});
//         }
//         for(auto i:pre_suff) {
//             if(mp.find(i.first)!=mp.end() and mp.find(i.second)!=mp.end()) {
//                 if(i.first==i.second) {
//                     ans+=mp[i.first]*(mp[i.first]-1);
//                 }else {
//                     ans+=mp[i.first]*mp[i.second];
//                 }
//             }
//         }
//         return ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) {
                    continue;
                }
                if(nums[i]+nums[j]==target) {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
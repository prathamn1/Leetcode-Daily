class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int num=nums.size(),ans=0,n=target.size();
        unordered_map<string,int>mp;
        for(auto i:nums) {
            mp[i]++;
        }
        
        vector<pair<string,string>>pre_suff;
        string pre=target,suff="";
        pre_suff.push_back({pre,suff});
        for(int i=n-1;i>=0;i--) {
            suff=target[i]+suff;
            pre.pop_back();
            pre_suff.push_back({pre,suff});
        }
        // for(auto [str,ct]:pre_suff) {
        //     cout<<str<<" "<<ct<<endl;
        // }
        for(auto i:pre_suff) {
            if(mp.find(i.first)!=mp.end() and mp.find(i.second)!=mp.end()) {
                if(i.first+i.first==target) {
                    ans+=mp[i.first]*(mp[i.first]-1);
                }else {
                    ans+=mp[i.first]*mp[i.second];
                }
            }
        }
        return ans;
        // for(int i=0;i<num;i++) {
        //     for(int j=0;j<num;j++) {
        //         if(i==j) {
        //             continue;
        //         }
        //         if(nums[i]+nums[j]==target) {
        //             ans+=1;
        //         }
        //     }
        // }
        // return ans;
    }
};
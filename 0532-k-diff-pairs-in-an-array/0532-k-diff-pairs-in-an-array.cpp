class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums) {
            mp[i]++;
        }
        int ans=0;
        for(auto [i,j]:mp) {
            if(k==0 and mp[i]>1) {//edge case for k==0 as an element can make pair with the same element haiving same value
                ans+=1;
            }else if(k!=0 and mp.find(i+k)!=mp.end()){
                ans+=1;
            }  
        }
        return ans;
    }
};
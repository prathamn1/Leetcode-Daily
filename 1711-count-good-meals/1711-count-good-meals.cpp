class Solution {
public:
    int countPairs(vector<int>& delic) {
        long long mod=1000000007;
        long long ans=0;
        unordered_map<long,long>mp;
        vector<long long>pow_2={1};
        for(long long i=1;i<=21;i++) {
            pow_2.push_back(pow_2.back()*2);
        }
        for(auto i:delic) {
            for(auto target:pow_2) {
                if(mp.find(target-i)!=mp.end()) {
                    ans+=mp[target-i];
                }
            }
            mp[i]++;
        }
        return ans%mod;
    }
};
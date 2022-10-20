class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        // for(auto i:mp) cout<<i.first<<" "<<i.second<<endl;
        for(auto [i,j]:mp) {
            pq.emplace(make_pair(j,i));
            if(pq.size()>k) {
                pq.pop();
            }
        }
        vector<int>ans(k);
        for(int i=k-1;i>=0;i--) {
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
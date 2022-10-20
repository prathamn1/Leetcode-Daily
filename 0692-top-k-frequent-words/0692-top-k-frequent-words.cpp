class Solution {
public:
    static bool comp(pair<string,int>&a , pair<string,int> & b) {
        return a.second>b.second or (a.second==b.second and a.first<b.first);
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(&comp)> pq(comp);
        unordered_map<string,int>freq;
        for(auto i:words) {
            freq[i]++;
        }
        vector<string>ans(k);
        for(auto p:freq) {
            pq.emplace(p);
            if(pq.size()>k) {
                pq.pop();
            }
        }
        for(int i=k-1;i>=0;i--) {
            ans[i]=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
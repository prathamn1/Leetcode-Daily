class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto i:s) {
            freq[i]++;
        }
        // priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)>pq(&cmp);
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        for(auto [i,j]:freq) {
            pq.push({j,i});
        }
        string ans="";
        while(not pq.empty()) {
            pair<int,char>char_freq=pq.top();
            pq.pop();
            for(int i=0;i<char_freq.first;i++) {
                ans+=char_freq.second;
            }
        }
        return ans;
    }
};
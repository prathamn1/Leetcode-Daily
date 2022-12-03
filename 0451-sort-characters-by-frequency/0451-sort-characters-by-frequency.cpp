class Solution {
public:
    static bool cmp(pair<char,int>&a,pair<char,int>&b) {
        return a.second<b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto i:s) {
            freq[i]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(&cmp)>pq(cmp); 
        // priority_queue<pair<int,char>,vector<pair<int,char>>>pq;  //36ms
        // for(auto [i,j]:freq) {
        //     pq.push({j,i});
        // }
        for(auto pr:freq) {
            pq.push(pr);
        }
        string ans="";
        while(not pq.empty()) {
            pair<char,int>char_freq=pq.top();
            pq.pop();
            for(int i=0;i<char_freq.second;i++) {
                ans+=char_freq.first;
            }
        }
        return ans;
    }
};
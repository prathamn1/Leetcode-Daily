class Solution {
public:
    static bool cmp(pair<char,pair<int,int>>&a,pair<char,pair<int,int>>&b) {
        if(a.second.first==b.second.first) {
            return a.second.second>b.second.second;
        }
        return a.second.first<b.second.first;
    }
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,pair<int,int>>freq;//map : key=char , value : pair (frequency , first_ appearance)
        for(int i=n-1;i>=0;i--) {
            freq[s[i]].second=i; // setting the index of character since traversing backward at last it will store the first appearance
            freq[s[i]].first++;//incrementing the frequency
        }
        priority_queue<pair<char,pair<int,int>>,vector<pair<char,pair<int,int>>>,decltype(&cmp)>pq(cmp); 
        for(auto pr:freq) {
            pq.push(pr);
        }
        string ans="";
        while(not pq.empty()) {
           pair<char,pair<int,int>>char_freq=pq.top();
            pq.pop();
            for(int i=0;i<char_freq.second.first;i++) {
                ans+=char_freq.first;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        unordered_set<int>unique_freq;
        for(auto i:arr) {
            freq[i]++;
        }
        for(auto [i,j]:freq) {
            unique_freq.insert(j);
        }
        return unique_freq.size()==freq.size();
    }
};
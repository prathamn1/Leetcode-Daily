class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>taken_elements,hashmap;
        for(auto i:nums) {
            hashmap.insert(i);
        }
        int ans=0;
        for(auto start:hashmap) {
            if(taken_elements.find(start)!=taken_elements.end()) {
                
                continue;
            }
            int i=start;
            while(hashmap.find(i)!=hashmap.end()) {
                taken_elements.insert(i);
                i++;
            }
            ans=max(ans,i-start);
        }
        return ans;
    }
};
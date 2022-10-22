class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        for(auto i:s1) {
            mp1[i]++;
        }
        int n=s2.size(),window_size=s1.size(),req_count=mp1.size(),curr_count=0,l=0,r=0;
        while(r<n) {
            
            if(r-l+1<=window_size) {
                mp2[s2[r]]++;
                if(mp2[s2[r]]==mp1[s2[r]]) {
                    curr_count++;
                }else if (mp2[s2[r]]==mp1[s2[r]]+1) {
                    curr_count--;
                }
                r++;    
            }else {
                mp2[s2[l]]--;
                if(mp2[s2[l]]==mp1[s2[l]]) {
                    curr_count++;
                }else if(mp2[s2[l]]==mp1[s2[l]]-1) {
                    curr_count--;
                }
                l++;
            }
            if(curr_count==req_count) {
                return true;
            }
            
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp_patt,curr_map;
        vector<int>ans;
        for(auto i:p) {
            mp_patt[i]++;
        }
        int n=s.size(),curr_count=0,req_count=mp_patt.size(),l=0,r=0,window_size=p.size();
        while(r<n) {
            if(r-l+1<=window_size) {
                curr_map[s[r]]++;
                if(curr_map[s[r]]==mp_patt[s[r]]) {
                    curr_count++;
                }else if (curr_map[s[r]]==mp_patt[s[r]]+1) {
                    curr_count--;
                }
                r++;
            }else {
                curr_map[s[l]]--;
                if(curr_map[s[l]]==mp_patt[s[l]]) {
                    curr_count++;
                }else if (curr_map[s[l]]==mp_patt[s[l]]-1) {
                    curr_count--;
                }
                l++;
            }
            if(curr_count==req_count) {
                ans.emplace_back(l);
            }
        }
        return ans;
    }
};
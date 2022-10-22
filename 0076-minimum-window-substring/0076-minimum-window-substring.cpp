class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp_t,curr_map;
        int curr_count=0,l=0,r=0,n=s.size();
        pair<int,int>ans={-1,INT_MAX};//starting_index,length_of string
        for(auto i:t) {
            mp_t[i]++;
        }
        int req_size=mp_t.size();
        while(l<=r and r<n) {
            curr_map[s[r]]++;
            if(curr_map[s[r]]==mp_t[s[r]]) {
                curr_count++;
            }
            if(curr_count==req_size) {
                // ans.first=l;
                // ans.second=r-l+1;
                while(l<=r and curr_count==req_size) {
                    if(r-l+1<ans.second) {
                        ans.second=r-l+1;
                        ans.first=l;
                    }  
                    curr_map[s[l]]--;
                    if(curr_map[s[l]]<mp_t[s[l]]) {
                        curr_count--;
                        l+=1;
                        break;
                    }
                    l+=1;    
                }
            }
            r+=1;
        }
        if(ans.first==-1) {
            return "";
        }
        return s.substr(ans.first,ans.second);
    }
};
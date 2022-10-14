class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        // for(auto i:mp) {
        //     cout<<i.first<<"  :  ";
        //     for(auto j:i.second) {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(auto i:words) {
            int prev=-1;
            bool found=true;
            for(auto ch:i) {
                int k=upper_bound(mp[ch].begin(),mp[ch].end(),prev)-mp[ch].begin();
                // cout<<k<<" ";
                if(k==mp[ch].size()) {
                    found=false;
                    break;
                }else {
                    prev=mp[ch][k];
                }
            }
            // cout<<endl;
            if(found) {
                ans+=1;
            }
        }
        return ans;
    }
};
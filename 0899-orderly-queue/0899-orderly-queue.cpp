class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans="";
        if(k==1) {
            ans=s;
            for(int i=0;i<s.size();i++) {
                s=s.substr(1,s.size())+s[0];
                if(ans>s) {
                    ans=s;
                }
            }
        }
        else {
            vector<char>st(s.begin(),s.end());
            sort(st.begin(),st.end());
            for(auto ch : st) {
                ans+=ch;
            }
        }
        return ans;
    }
};
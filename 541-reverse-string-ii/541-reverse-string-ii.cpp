class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        string ans;
        int l=0;
        while(l<n) {
            for(int i=min(l+k-1,n-1);i>=l;i--) {
                ans+=s[i];
            }
            l+=k;
            for(int i=l;i<min(l+k,n);i++) {
                ans+=s[i];
            }
            l+=k;
        }
        return ans;
    }
};
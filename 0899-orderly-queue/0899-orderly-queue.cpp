//if k==1 then we will see that at one time we could send the front character to the back so brute force it and find the minimum of all strings
//if k==2 lets we have a string abcccc then we could form the strings as ab

class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans="";
        if(k==1) {
            ans=s;
            for(int i=0;i<s.size();i++) {
                s=s.substr(1)+s[0];
                if(ans>s) {
                    ans=s;
                }
            }
        }
        else {
            sort(s.begin(),s.end());
            return s;
        }
        return ans;
    }
};
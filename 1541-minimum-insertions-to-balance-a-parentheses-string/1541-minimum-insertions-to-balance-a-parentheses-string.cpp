class Solution {
public:
    int minInsertions(string s) {
        int i=0,ct=0,ans=0,n=s.size();
        while(i<n) {
            if(s[i]==')') {
                if(i+1<n and s[i+1]==')') {
                    i+=2;
                }
                else {
                    ans+=1;
                    i+=1;
                }
                ct-=1;
            } else {
                ct+=1;
                i+=1;
            }
            if(ct<0) {
                ans+=1;
                ct=0;
            }
        }
        return ans+ct*2;
    }
};
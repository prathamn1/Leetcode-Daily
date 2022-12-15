class Solution {
public:
    int count_palindrome(int left,int right,int n,string s) {
        int ct=0;
        while(left>=0 and right<n) {
            if(s[left--]==s[right++]) {
                ct++;
            }else {
                break;
            }
        }
        return ct;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++) {
            ans+=count_palindrome(i,i,n,s)+count_palindrome(i,i+1,n,s);
        }
        return ans;
    }
};
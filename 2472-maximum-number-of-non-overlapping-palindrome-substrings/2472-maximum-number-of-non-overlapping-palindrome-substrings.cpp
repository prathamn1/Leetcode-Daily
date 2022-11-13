class Solution {
public:
    bool is_palindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i++]!=s[j--]) {
                return false;
            }
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int max_palindrome_parts=0,n=s.size();
        for(int i=0;i<n;i++) {
            string st="";
            for(int j=i;j<n;j++) {
                st+=s[j];
                if(st.size()>k+1) {  // actually no need for checking palindromic string if it's size exceeds k+1 because if K+2 sized string becomes palindrome then automatically one of k+1 or k will be palindrome so no need to take k+2 sized string as we need to maximize the partition
                    break;
                }
                if(st.size()>=k and is_palindrome(st)) {
                    max_palindrome_parts+=1;
                    i=j;   // after that it will go for incrementing in for loop so next iteration will automatically become j+1
                    break;
                }
            }
        }
        return max_palindrome_parts;
    }
};
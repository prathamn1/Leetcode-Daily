class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size(),left=0,right=s.size()-1;
        string ans=s;
        unordered_set<char>vowels={'a','e','i','o','u'};
        while(left<n and right>=0) {
            while(left<n and vowels.find(tolower(s[left]))==vowels.end()) {
                left++;
            }
            while(right>=0 and vowels.find(tolower(s[right]))==vowels.end()) {
                right--;
            }
            if(left<n and right>=0) {
                ans[left]=s[right];
            }
            left++;
            right--;
        }
        return ans;
    }
};
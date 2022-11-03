class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>freq;
        for(auto i:words) {
            freq[i]++;
        }
        int length=0;
        bool odd=false;
        for(auto [i,j] : freq) {
            string rev_i=i;
            reverse(rev_i.begin(),rev_i.end());
            
            if(i==rev_i) {
                length+=4*(j/2);
                if(not odd and j%2) {
                    odd=true; 
                }
            }
            else if(freq.find(rev_i)!=freq.end()) {
                length+=2*min(j,freq[rev_i]);
            }
        }
        if(odd){
            return length+2;
        }else {
            return length;
        }
    }
};
//great question so make two maps->
/*
one for string s1 and other the current map which keeps on changing and it keeps the character of the current window;
our window size is len(s1)
so add the character when current_size<=window_size now AFTER adding the character notice that if 
the character is of the size == in map1 then increase the curr_count and if it crosses the size ie. its current frequency is 1+required_frequency then decrease the curr_count by 1 and there is no need for decreasing count again and again as we have decreased the contribution made by that character.
similarly after removing the character when our window is full notice that 
if the frequency equals required then increase the count by 1 
but if the frequency is one less than the required frequency then decrease the count by one.
and finally check for if the required count is equal to the current_count
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        for(auto i:s1) {
            mp1[i]++;
        }
        int n=s2.size(),window_size=s1.size(),req_count=mp1.size(),curr_count=0,l=0,r=0;
        while(r<n) {
            if(r-l+1<=window_size) {
                mp2[s2[r]]++;
                if(mp2[s2[r]]==mp1[s2[r]]) {
                    curr_count++;
                }else if (mp2[s2[r]]==mp1[s2[r]]+1) {
                    curr_count--;
                }
                r++;    
            }else {
                mp2[s2[l]]--;
                if(mp2[s2[l]]==mp1[s2[l]]) {
                    curr_count++;
                }else if(mp2[s2[l]]==mp1[s2[l]]-1) {
                    curr_count--;
                }
                l++;
            }
            if(curr_count==req_count) {
                return true;
            }
            
        }
        return false;
    }
};
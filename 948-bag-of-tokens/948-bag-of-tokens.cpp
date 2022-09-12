class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int curr_power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,curr_score=0,ans=0;
        while(i<=j) {
            if(curr_power>=tokens[i]) {
                curr_power-=tokens[i];
                curr_score+=1;
                i+=1;
                ans=max(ans,curr_score);
            } else if(curr_score) {
                curr_power+=tokens[j];
                curr_score-=1;   
                j-=1;
            }else {
                break;
            }
        }
        return ans;
    }
};
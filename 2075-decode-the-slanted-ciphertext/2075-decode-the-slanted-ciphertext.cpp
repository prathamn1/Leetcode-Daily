
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size(),cols=n/rows,curr_col=0,curr_row=0;
        string ans;
        vector<string>word(cols);
        for(int i=0;i<n;i++) {
            if(curr_col-curr_row>=0) {
                word[curr_col-curr_row]+=encodedText[i];
            }
            curr_col+=1;
            if(curr_col==cols) {
                curr_col=0;
                curr_row+=1;
            }
        }
        for(auto str:word) {
            ans+=str;
        }
        while(ans.back()==' ') {
            ans.pop_back();
        }
        return ans;
    }
};
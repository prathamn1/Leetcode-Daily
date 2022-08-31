class Solution {
public:
    bool check_palindrome(string s, int start, int end) {
        while(start<end){
            if(s[start++]!=s[end--]) {
                return false;
            }
        }
        return true;
    }
    void dfs(string s,vector<vector<string>> &ans ,vector<string>&current,int start) {
        if(start==s.size()) {
            ans.push_back(current);
            return;
        }
        for(int i=start;i<s.size();i++) {
            if(check_palindrome(s,start,i)) {
                current.push_back(s.substr(start,i-start+1));
                dfs(s,ans,current,i+1);
                current.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>current;
        dfs(s,ans,current,0);
        return ans;
    }
};
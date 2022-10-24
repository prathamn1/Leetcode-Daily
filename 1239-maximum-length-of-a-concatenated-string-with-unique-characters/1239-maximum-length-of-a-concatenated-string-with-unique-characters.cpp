//you can also use vector<char>(26,false) for improving time and space complexity 
class Solution {
public:
    void solve(int curr_index,vector<bool>curr_set,vector<string>&arr,int &ans,int curr_len) {
        if(curr_index==arr.size()) {
            ans=max(curr_len,ans);
            return ;
        }
        solve(curr_index+1,curr_set,arr,ans,curr_len);
        for(auto i:arr[curr_index]) {
            if(!curr_set[i-97]) {
                curr_len++;
                curr_set[i-97]=true;
            }else {
                return ;
            }
        }
        solve(curr_index+1,curr_set,arr,ans,curr_len);
        
    }
    int maxLength(vector<string>& arr) {
        vector<bool>curr_set(26,false);
        int ans=0;
        solve(0,curr_set,arr,ans,0);
        return ans;
    }
};
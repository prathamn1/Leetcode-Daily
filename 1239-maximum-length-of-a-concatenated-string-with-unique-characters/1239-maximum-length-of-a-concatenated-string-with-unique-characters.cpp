//you can also use vector<char>(26,false) for improving time and space complexity 
class Solution {
public:
    void solve(int curr_index,set<char>curr_set,vector<string>&arr,int &ans) {
        if(curr_index==arr.size()) {
            ans=max<int>(curr_set.size(),ans);
            return ;
        }
        solve(curr_index+1,curr_set,arr,ans);
        // set<char>temp(curr_set.begin(),curr_set.end());
        for(auto i:arr[curr_index]) {
            if(curr_set.find(i)==curr_set.end()) {
                curr_set.insert(i);
            }else {
                return ;
            }
        }
        solve(curr_index+1,curr_set,arr,ans);
        
    }
    int maxLength(vector<string>& arr) {
        set<char>curr_set;
        int ans=0;
        solve(0,curr_set,arr,ans);
        return ans;
    }
};
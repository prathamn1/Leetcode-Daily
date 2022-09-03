#include<cmath>
class Solution {
public:
    void solve(int digit,vector<int>curr_num,int n,int k,vector<int>&ans) {
        if(digit<0 or digit>9 or curr_num.size()>n) {
            return ;
        }
        curr_num.push_back(digit);
        if(curr_num.size()==n) {
            int num=0;
            for(int i=0;i<n;i++) {
                num=curr_num[i]+num*10;
            }     
            ans.push_back(num);
        }
        solve(digit+k,curr_num,n,k,ans);
        if(k!=0) {
        solve(digit-k,curr_num,n,k,ans);
        }
        curr_num.pop_back();
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        vector<int>curr_num;
        for(int i=1;i<=9;i++) {
            solve(i,curr_num,n,k,ans);
        }
        return ans;
    }
};
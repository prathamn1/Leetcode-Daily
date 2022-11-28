class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_max=prices.back(),ans=0;
        for(auto i=prices.end()-1;i>=prices.begin();i--) {
            ans=max(ans,curr_max-*i);
            curr_max=max(curr_max,*i);
        }
        return ans;
    }
};
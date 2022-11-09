class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--) {
            while(not st.empty() and temp[i]>=temp[st.top()]) {
                st.pop();
            }
            if(not st.empty()) {
                ans[i]=st.top()-i;
            }else {
                ans[i]=0;
            }
            st.push(i);
        }
        return ans;
    }
};
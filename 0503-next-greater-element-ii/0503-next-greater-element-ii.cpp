class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>nge(n);
        
        for(int i=2*n-1;i>=0;i--) {
            while(not st.empty() and nums[i%n]>=nums[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                nge[i%n]=-1;
            }else {
                nge[i%n]=nums[st.top()];
            }
            st.push(i%n);
        }
        return nge;
    }
};
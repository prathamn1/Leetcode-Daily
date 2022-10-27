class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        vector<int> arr(st.begin(),st.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++) {
            int k=upper_bound(arr.begin(),arr.end(),arr[i]+n-1)-arr.begin();
            ans=min(ans,n-(k-i));
        }
        return ans;
    }
};
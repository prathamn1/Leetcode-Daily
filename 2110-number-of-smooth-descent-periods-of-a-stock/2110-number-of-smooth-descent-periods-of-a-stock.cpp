class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        long long l=0,r=0,n=nums.size(),ans=0;
        while(r<n) {
            if(r>0 and r<n and nums[r-1]-nums[r]!=1) {
                l=r;
            }
            ans+=r-l+1;
            r+=1;
        }
        return ans;
    }
};
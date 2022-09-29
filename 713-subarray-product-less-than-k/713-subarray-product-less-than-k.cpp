class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=size(nums),left=0,right=0,ans=0,prod=1; 
        while(right<n) {
            prod*=nums[right];
            while(left<=right and prod>=k) {
                prod/=nums[left];
                left++;
            }
            ans+=right-left+1;  // remember this formula while calculating added subarray of a sliding window
            right++;
        }
        return ans;
    }
};
//great problem for practising as uses the concept of window sliding to count subarrays . remember at every step ans+="r-l+1" states that no. of subarrays which are starting from l till r .
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int curr_score=0,curr_sum=0,n=nums.size(),l=0,r=0,ans=0;
        while(r<n) {
            curr_sum+=nums[r];
            curr_score=curr_sum*(r-l+1);
            while(curr_score>=k) {
                curr_sum-=nums[l];
                l+=1;
                curr_score=curr_sum*(r-l+1);
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};
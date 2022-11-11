class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0,right=0,n=nums.size();
        while(right<n-1) {
            if(nums[right]!=nums[right+1]) {
                nums[left]=nums[right];
                left++;
            }
            right++;
        }
        nums[left]=nums[right];
        return left+1;
    }
};
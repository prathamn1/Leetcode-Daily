class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size(),first_element_freq=1,second_element_freq=0;
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1]) {
                return nums[i];
            }
            if(nums[i]==nums[0]) {
                first_element_freq++;
            }else if(nums[i]==nums[1]) {
                second_element_freq++;
            }
        }
        return first_element_freq>1?nums[0]:nums[1];
    }
};
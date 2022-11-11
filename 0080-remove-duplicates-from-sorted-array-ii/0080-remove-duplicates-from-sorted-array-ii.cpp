
// int removeDuplicates(vector<int>& nums) {
//     int i = 0;
//     for (int n : nums)
//         if (i < 2 || n > nums[i-2])
//             nums[i++] = n;
//     return i;
// }


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0,right=0,n=nums.size();
        while(right<n-1) {
            if(nums[right]!=nums[right+1]){
                if(right-1>=0 and nums[right]==nums[right-1]) {
                    nums[left]=nums[right];
                    nums[left+1]=nums[right];
                    left+=2;
                }else {
                    nums[left]=nums[right];
                    left+=1;
                }
            } 
            right++;
        }
        if(right-1>=0 and nums[right]==nums[right-1]) {
            nums[left]=nums[right];
            nums[left+1]=nums[right];
            left+=2;
        }else {
            nums[left]=nums[right];
            left+=1;
        }
        return left;
    }
};


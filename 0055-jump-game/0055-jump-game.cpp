class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reaching_position=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--) {
            if(i+nums[i]>=reaching_position) {
                reaching_position=i;
            }
        }
        return (reaching_position==0)?true:false;
    }
};
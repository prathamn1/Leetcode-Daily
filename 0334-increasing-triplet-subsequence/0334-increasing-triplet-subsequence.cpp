class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) {
            return false;
        }
        int first=INT_MAX,second=INT_MAX;
        for(auto i:nums) {
            if(i<first) {
                first=i;
            }else if(i>first and i<second) {
                second=i;
            }else if(i>second) {
                return true;
            }
        }
        return false;
    }
};
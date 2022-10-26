class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mod_k;
        mod_k[0]=-1; // so that our prefix can also be a subarray
        int pre_sum=0;
        for(int i=0;i<nums.size();i++) {
            pre_sum+=nums[i];
            if(mod_k.find(pre_sum%k)!=mod_k.end()) {
                if(abs(mod_k[pre_sum%k]-i)>1) {
                    return true;
                }    
            }else {
                mod_k[pre_sum%k]=i;
            }
        }
        return false;
    }
};
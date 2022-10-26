//Actually the question involved modular arithmetic as (a-b)%k = (a%k - b%k)%k so let's a be prefix sum till i th index and b be the prefix sum till jth index ( i<j) so the subarray from i to j will be divisible by k if (b-a)%k==0 or (b%k - a%k)%k =0 so b%k -a%k are divisible by k and now since b%k < k and a%k < k so for their difference to be divisible they must be equal or b%k==a%k for the equation to be true

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mod_k;
        mod_k[0]=-1; // so that our proper prefix can also be a subarray
        int pre_sum=0;
        for(int i=0;i<nums.size();i++) {
            pre_sum+=nums[i];
            if(mod_k.find(pre_sum%k)!=mod_k.end()) { //as we want the length greater than 1 so it is better that if we find the modulo m for some prefix then we must not update it's value or we must make sure that j-i>1
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
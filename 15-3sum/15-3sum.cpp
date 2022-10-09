class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()-2) {
            int l=i+1,r=nums.size()-1;
            while(l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r and nums[l]==nums[l+1]) {
                        l+=1;
                    }
                    l++;    
                }else if(sum<0) {
                    l++;
                }else {
                    r--;
                }
            }
            while(i<nums.size()-1 and nums[i]==nums[i+1]) {
                i+=1;
            }
            i+=1;
        }
        return ans;
    }
};
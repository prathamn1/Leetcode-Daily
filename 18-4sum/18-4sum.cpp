class Solution {
public:
    void threeSum(int start,vector<int>& nums,int target,vector<vector<int>>&ans) {
        target-=nums[start];
        int i=start+1;
        while(i<nums.size()-2) {
            int l=i+1,r=nums.size()-1;
            while(l<r) {
                long long sum=(long long)nums[i]+(long long)nums[l]+(long long)nums[r];
                if(sum==target) {
                    ans.push_back({nums[start],nums[i],nums[l],nums[r]});
                    while(l<r and nums[l]==nums[l+1]) {
                        l+=1;
                    }
                    l++;    
                }else if(sum<target) {
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
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;

        if(nums.size()<4) {
            return ans;
        }
        // vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        // for(auto i:nums) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int i=0;
        while(i<nums.size()-3) {
            threeSum(i,nums,target,ans);
            while(i<nums.size()-1 and nums[i]==nums[i+1]) {
                i++;
            }
            i+=1;
        }
        if(ans.size()==0) {
            return ans;
        }
        return ans;
    }
};
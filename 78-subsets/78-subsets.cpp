// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         ans.push_back({});
//         for(auto i:nums) {
//             int length=ans.size();
//             for(int j=0;j<length;j++) {
//                 vector<int>temp=ans[j];
//                 temp.push_back(i);
//                 ans.push_back(temp);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int total_subsets=1<<nums.size();
        for(int i=0;i<total_subsets;i++) {
            vector<int>temp;
            for(int j=0;j<nums.size();j++) {
                if(((i>>j)&1)==1) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
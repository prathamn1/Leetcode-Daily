//actually this is bruteforce solution and the only time at which it gives tle is when valueDiff =0 or when we have to find the same value two times/duplicates so if duplicates are present then it will pass otherwise it will fail so just to avoid this condition we can check for duplicacy of elements
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        if(valueDiff==0 and set<int>(nums.begin(),nums.end()).size()==n) {
            return false;
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<i+indexDiff+1 and j<n;j++) {
                if(abs((long long)nums[i]-nums[j])<=valueDiff) {
                    return true;
                }
            }
        }
        return false;
    }
};
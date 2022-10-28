class Solution {
public:
    int partition(vector<int>&nums,int s,int e)
    {
        int i=s;
        for(int j=s; j<e; j++)
        {
            if(nums[j]<=nums[e])
            {
                
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[e]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int s=0,e=nums.size()-1;
        k=nums.size()-k+1;
        while(1)
        {
            int p_idx=partition(nums,s,e);
            if(p_idx==k-1)
                return nums[p_idx];
            else if(p_idx>k-1)
                e=p_idx-1;
            else
                s=p_idx+1;
        }
        return -1;
    }
};
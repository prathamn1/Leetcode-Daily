class Solution:
    def maxDistance(self, nums1: List[int], nums: List[int]) -> int:
        l=0
        r=len(nums)-1
        ind=-1
        ans=float("-inf")
        for i in range(len(nums1)):
            l=max(ind,i)
            r=len(nums)-1
            ind=-1
            while l<=r:
                mid=l+(r-l)//2
                if nums1[i]<=nums[mid]:
                    ind=mid
                    l=mid+1
                else:
                    r=mid-1 
            # print(ind)
            ans=max(ans,ind-i)
        return max(0,ans)
    
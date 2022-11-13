from math import lcm
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        n,ans=len(nums),0
        for  i in range(n):
            lc=nums[i]
            for j in range(i,n):
                lc=lcm(lc,nums[j])
                if(lc>k):
                    break
                if lc==k:
                    ans+=1
        return ans
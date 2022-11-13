from math import gcd
class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        ans=0
        n=len(nums)
        for i in range(n):
            g=nums[i]
            for j in range(i,n):
                g=gcd(g,nums[j])
                if g==k:
                    ans+=1
        return ans
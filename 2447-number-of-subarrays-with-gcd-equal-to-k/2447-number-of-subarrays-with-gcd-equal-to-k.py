from math import gcd
class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        n=len(nums)
        ans=0
        for i in range(n):
            curr_gcd=nums[i]
            for j in range(i,n):
                curr_gcd=gcd(curr_gcd,nums[j])
                if curr_gcd==k:
                    ans+=1
                elif curr_gcd<k:
                    break
        return ans
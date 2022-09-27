class Solution:
    def maxSubArray(self, a: List[int]) -> int:
        ans=float('-inf')
        summation=0
        for i in a:
            summation+=i
            ans=max(ans,summation)
            if summation<0:
                summation=0
            
        return ans
class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        weighted_median=sorted(zip(nums,cost))
        total_cost,curr_cost,convert_to,ans=sum(cost),0,0,0
        for i,j in weighted_median:
            curr_cost+=j
            if curr_cost>total_cost//2:
                convert_to=i
                break
        for i,j in weighted_median:
            ans+=abs(i-convert_to)*j
        return ans
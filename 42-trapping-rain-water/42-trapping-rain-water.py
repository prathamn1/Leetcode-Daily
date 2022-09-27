class Solution:
    def trap(self, height: List[int]) -> int:
        max_left=height[0]
        max_right=height[-1]
        l=1
        r=len(height)-2
        ans=0
        while l<=r:
            if max_left<=max_right:
                if max_left>=height[l]:
                    ans+=max_left-height[l]
                else:
                    max_left=height[l]
                l+=1
            else:
                if max_right>=height[r]:
                    ans+=max_right-height[r]
                else:
                    max_right=height[r]
                r-=1
        return ans
            
            
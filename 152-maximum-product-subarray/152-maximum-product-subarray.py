class Solution:
    def maxProduct(self, a: List[int]) -> int:
        # the idea is to keep track of minimum and maximum product every time we multiply the new number
        
        maxp=minp=ans=a[0]
        i=1
        while i<len(a):
            ch1=maxp*a[i]
            ch2=minp*a[i]
            maxp=max(ch1,ch2,a[i])
            minp=min(ch1,ch2,a[i])
            ans=max(maxp,ans)
            i+=1
        return ans
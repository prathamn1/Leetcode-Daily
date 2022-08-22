class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        i=len(colors)-1
        while colors[i]==colors[0]:
            i-=1
        j=0
        while colors[j]==colors[-1]:
            j+=1
        return max(i,len(colors)-j-1)
            
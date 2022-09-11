class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        n=len(intervals)
        arrival=[i[0] for i in intervals]
        departure=[i[1] for i in intervals]
        arrival.sort()
        departure.sort()
        i=j=0
        maximum_platforms_taken=1
        platform_currently_engaged=0
        while(i<n and j<n):
            if arrival[i]<=departure[j]:
                platform_currently_engaged+=1
                i+=1
            else:
                j+=1
                platform_currently_engaged-=1
            maximum_platforms_taken=max(maximum_platforms_taken,platform_currently_engaged)
        return maximum_platforms_taken
#A bit greedy approach ,consider each intervals as trains which have their own arrival and departure time
#And as platforms are independent of trains so to minimize the number of platforms we first sort the arrival time and departure time separately and then traverse both by using two pointer i,j.
# arrival[i]<=departure[j] means that a train has arrived but not left yet which means we will have to increase the platform_currently_engaged to accomodate the new train at the station and if departure becomes smaller , then we subtract the currently_engaged_platform by 1 as that platform has now become empty.


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
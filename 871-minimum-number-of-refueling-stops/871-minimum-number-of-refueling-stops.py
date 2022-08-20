from queue import PriorityQueue
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        pq=PriorityQueue()
        max_reach_distance=startFuel
        ind=ans=0
        #Enter loop only if our maximum reachable distance is less than target
        while max_reach_distance<target:
        #Now once we enter the loop check for how many stations we can cross/jump with our current fuel capacity
            while ind<len(stations) and max_reach_distance>=stations[ind][0]:
                pq.put(-stations[ind][1])
                ind+=1
            # if we cannot increase our max_reach and also at this stage our max_reach is less than target so return -1
            if pq.empty():
                return -1
            #increase our max_reach_distance to the greatest fuel station till now
            max_reach_distance+=(-pq.get())
            ans+=1
        return ans
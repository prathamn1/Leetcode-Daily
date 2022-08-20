from queue import PriorityQueue
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        pq=PriorityQueue()
        max_reach_distance=startFuel
        ind=ans=0
        while max_reach_distance<target:
            while ind<len(stations) and max_reach_distance>=stations[ind][0]:
                pq.put(-stations[ind][1])
                ind+=1
            if pq.empty():
                return -1
            max_reach_distance+=(-pq.get())
            ans+=1
        return ans
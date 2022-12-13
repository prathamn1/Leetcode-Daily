class Solution:
    
    
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        r=len(robot)
        f=len(factory)
        robot.sort()
        factory.sort()
        dp=[[[-1 for _ in range(r+1)] for _ in range(f)] for _ in range(r)]
        def solve(robot_ind,factory_ind):
            if robot_ind==r:
                return 0
            if factory_ind==f:
                return float('inf')
            if(dp[robot_ind][factory_ind][factory[factory_ind][1]]!=-1):
                return dp[robot_ind][factory_ind][factory[factory_ind][1]]
            not_assign=solve(robot_ind,factory_ind+1)
            assign=0
            if factory[factory_ind][1]==0:
                assign=solve(robot_ind,factory_ind+1)
            else:
                factory[factory_ind][1]-=1
                assign=solve(robot_ind+1,factory_ind)+abs(factory[factory_ind][0]-robot[robot_ind])
                factory[factory_ind][1]+=1
            dp[robot_ind][factory_ind][factory[factory_ind][1]]=min(not_assign,assign)
            return dp[robot_ind][factory_ind][factory[factory_ind][1]]
        return solve(0,0)
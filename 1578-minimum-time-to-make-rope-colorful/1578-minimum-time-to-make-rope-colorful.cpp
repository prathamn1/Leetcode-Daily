class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size(),i=0,j,ans=0,max_time,remove_time;
        while(i<n) {
            j=i,max_time=INT_MIN,remove_time=0;
            while(colors[j]==colors[j+1]) {
                max_time=max(neededTime[j],max_time);
                remove_time+=neededTime[j++];
            }
            if(remove_time!=0) {
                max_time=max(neededTime[j],max_time);
                remove_time+=neededTime[j];
                ans+=remove_time-max_time;
            }
            i=j+1;
        }
        return ans;
    }
};
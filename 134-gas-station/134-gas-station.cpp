//greedy problem and not very intuitive and understandable just the important thing is that if our total gas>=total cost then only we will have a solution and that is only one solution


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_fuel=0;
        int ans=0;
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) {
            return -1;
        } else {// there is a solution
            for(int i=0;i<gas.size();i++) {
                curr_fuel+=gas[i]-cost[i];
                if(curr_fuel<0) {
                    curr_fuel=0;
                    ans=i+1;
                }
            }
        }
        return ans;
    }
};
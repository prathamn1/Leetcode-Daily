class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& running, long long budget) {
        deque<int>dq;
        long long int curr_sum=0,l=0,r=0,ans=0,total_cost=0,n=running.size();
        while(r<charge.size()) {
            while(r<n and total_cost<=budget) {
                curr_sum+=running[r];
                while(not dq.empty() and charge[r]>charge[dq.back()]) {
                    dq.pop_back();
                }
                dq.push_back(r);
                total_cost=charge[dq.front()]+(r-l+1)*curr_sum;
                if(total_cost<=budget) {
                    ans=max(ans,r-l+1);  
                    r++;
                }     
            }
            while(l<=r and total_cost>budget) {
                curr_sum-=running[l];
                while(not dq.empty() and dq.front()<=l) {
                    dq.pop_front();
                }
                if(not dq.empty()) {
                    total_cost=charge[dq.front()]+(r-l+1)*curr_sum;
                }else {
                    total_cost=0;
                }
                l++;  
            }
            
            r++;  
            if(l==r) {
                dq.clear();
                l=r;
            }
        }
        return (int)ans;
    }
};

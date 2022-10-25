//great question using the concept of the question to find the maximum element within all subarrays of size k
/* 
so we will use two pointer l and r for the subarray and we will first increase r till our r is standing on the position where on including that our total_cost is greater than our budget after that we tend to increase our left pointer with removing the elements from our window
*/

class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& running, long long budget) {
        deque<int>dq;
        long long int curr_sum=0,l=0,r=0,ans=0,total_cost=0,n=running.size();
        while(r<charge.size()) {
            while(r<n and total_cost<=budget) {
                curr_sum+=running[r];
                while(not dq.empty() and charge[r]>charge[dq.back()]) { // finding the maximum element index till now from l to r (inclusive)
                    dq.pop_back();
                }
                dq.push_back(r);
                total_cost=charge[dq.front()]+(r-l+1)*curr_sum;
                if(total_cost<=budget) { 
                    ans=max(ans,r-l+1);  
                    r++;
//incrementing r inside this block because our r must be standing on the position which has its total_cost > than budget so if total_cost > budget then, we will not enter this block and our r will be on the required position
                }     
            }
            while(l<=r and total_cost>budget) {
                curr_sum-=running[l];
                while(not dq.empty() and dq.front()<=l) { //yahi wo line hai , must use "<=" here as we tend to say that we are removing the element at our current l postion as we are decrementing its value from curr_sum so we must also remove it's contribution (if possible ) from the maximum charge ( or our deque )
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
            // if(l==r) {
            //     dq.clear();
            //     l=r;
            // }
        }
        return (int)ans;
    }
};

// Approach 1 : prefix sum;
/*
Just make one prefix sum array of size 2*10^5 and initialize position containing fruits as number of fruits ans others as zero and then take prefix sum of them
for calculating the number of fruits in range [l,r] : prefix[r]-prefix[l-1] and remember that
l-1>=0 
Now there are two types of operations like -
--double the steps on left and remaining steps on right 

for this since you have to go double steps on left you can have remaining steps as (k-2*left) on right thus calculate the fruits on range left,right 


--double the steps on right and remaining steps on left
similar to above
and calculate the maximum out of two operations;



for the second approach no need to do prefix sum just use two pointer approach initially both left and right are 0 so take fruits on pos=fruits[0][1] and if the path is valid that is position of fruits on l and position of fruits on r then try to expand the range by increasing r and take the fruits on that position but if the path goes wrong ie. takes more than k steps then move l forward untill path becomes valid or l equals r.

 

*/


//second approach
class Solution {
public:
    bool is_valid(int l,int r,int start,int k) {
        if(r<=start) {
            return start-l<=k;
        }else if(l>=start) {
            return r-start<=k;
        }else {
            if((start-l)*2+(r-start)<=k or (start-l)+(r-start)*2<=k) {
                return true;
            }
            return false;
        } 
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        int n=fruits.size();
        int left=0,right=0,curr_fruits=0,ans=0;
        while(right<n) {
            curr_fruits+=fruits[right][1];
            while(left<=right and is_valid(fruits[left][0],fruits[right][0],start,k)==false) {
                curr_fruits-=fruits[left][1];
                left+=1;
            }
            ans=max(ans,curr_fruits);
            right+=1;
        }
        return ans;
    }
};
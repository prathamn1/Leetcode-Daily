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
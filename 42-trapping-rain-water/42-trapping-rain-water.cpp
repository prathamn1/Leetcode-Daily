class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,max_left=height[0],max_right=height[height.size()-1];
        int ans=0;
        while(left<right) {
            if (max_left<=max_right){
                left+=1;
                ans+=max(0,max_left-height[left]);
                max_left=max(max_left,height[left]);                  
            }else {
                right-=1;   
                ans+=max(0,max_right-height[right]);
                max_right=max(max_right,height[right]);
            }            
        }
        return ans; 
    }
};
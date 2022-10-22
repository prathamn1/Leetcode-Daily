class Solution {
public:
    
    static bool comp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b) {
        return a.first>b.first;
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(&comp)>pq(comp);
        //list_index,element_index
        int n=nums.size(),maxi=INT_MIN;
        vector<int>ans={-100001,100001};
        for(int i=0;i<n;i++) {
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        while(true) {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int element=p.first;
            if( (maxi-element<ans[1]-ans[0]) or (maxi-element==ans[1]-ans[0] and ans[0]>element)) {
                ans[0]=element;
                ans[1]=maxi;
            }
            if(p.second.second+1<nums[p.second.first].size()) {
                pq.push({nums[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
                maxi=max(maxi,nums[p.second.first][p.second.second+1]);
            }else {
                break;
            }
        }
        return ans;
    }
};
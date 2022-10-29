class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>plants;
        int n= plantTime.size();
        for(int i=0;i<n;i++) {
            plants.push_back({plantTime[i],growTime[i]});
        }
        sort(plants.begin(),plants.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });
        // for(auto i:plants) {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int ans=0,curr_day=0;
        for(int i=0;i<n;i++) {
            curr_day+=plants[i].first;
            // cout<<curr_day<<endl;
            ans=max(ans,curr_day+plants[i].second);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>points;
        vector<vector<int>>ans;
        multiset<int>height;
        for(auto i : buildings) {
            points.push_back({i[0],-i[2]});
            points.push_back({i[1],i[2]});
        }
        
        sort(points.begin(),points.end());
        
        int curr_height=0;
        height.insert(curr_height);
        for(auto i: points) {
            if(i.second<0) {
                height.insert(-i.second);
            }else {
                height.erase(height.find(i.second));
            }
            if(*(height.rbegin())!=curr_height) {
                curr_height=*(height.rbegin());
                ans.push_back({i.first,curr_height});
            }
        }
        return ans;
    }
};
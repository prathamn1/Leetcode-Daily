class Solution {
public:
    static int cmp(pair<int,int>&a,pair<int,int>&b) {
        return a.first>b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>team;
        for(int i=0;i<n;i++) {
            team.push_back(make_pair(efficiency[i],speed[i]));
        }
        sort(team.begin(),team.end(),cmp);
        long long int ans=0,speed_sum=0;
        for(int i=0;i<n;i++) {
            pq.push(team[i].second);
            speed_sum+=team[i].second;
            if(pq.size()>k) {
                speed_sum-=pq.top();
                pq.pop();
            }
            ans=max<long long int>(ans,speed_sum*(team[i].first));
        }
        return ans%1000000007;
    }
};
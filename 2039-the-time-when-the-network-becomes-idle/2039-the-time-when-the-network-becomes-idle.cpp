class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // int n=;
        int time[patience.size()];
        vector<int> adj[patience.size()];
        for(vector<int> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int>q;
        vector<bool> visited(patience.size(),false);
        q.push(0);
        visited[0]=true;
        int level=0;
        while( not q.empty()) {
            int st=q.size();
            for(int i=0;i<st;i++) {
                int k=q.front();
                q.pop();
                time[k]=2*level;
                for(int j:adj[k]) {
                    if(not visited[j]) {
                    q.push(j);
                    visited[j]=true;
                    }
                }        
            }
            level+=1;
        }
        int ans=0;
        for(int i=0;i<patience.size();i++) {
            if(time[i]<=patience[i]) {
                ans=max(ans,time[i]);
            }else {
                int multi=ceil((double)time[i]/patience[i])-1;
                ans=max(ans,time[i]+patience[i]*multi);
            }   
        }
        return ans+1;
    }
};
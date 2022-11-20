class Solution {
public:
    
    int dfs(int curr_node,int& seats , bool is_visited [],vector<int> adj[],long long int &total_fuel) {
        int curr_people=1;
        is_visited[curr_node]=true;
        for(auto child:adj[curr_node]) {
            if(not is_visited[child]) {
                curr_people+=dfs(child,seats,is_visited,adj,total_fuel);
            }
        }
        if(curr_node!=0)
        total_fuel+=ceil(curr_people/(double)seats);
        return curr_people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int> adj[n+1];
        for(auto edge:roads) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bool is_visited[n+1];
        memset(is_visited,0,sizeof(is_visited));
        long long int total_fuel=0;
        dfs(0,seats,is_visited,adj,total_fuel);
        return total_fuel;
    }
};
class Solution {
public:
    long long int total_fuel=0;
    int dfs(int curr_node,int& seats , vector<bool>& is_visited,unordered_map<int,vector<int>>&adj) {
        int curr_people=1;
        is_visited[curr_node]=true;
        for(auto child:adj[curr_node]) {
            if(not is_visited[child]) {
                curr_people+=dfs(child,seats,is_visited,adj);
            }
        }
        if(curr_node!=0)
        total_fuel+=ceil(curr_people/(double)seats);
        return curr_people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        unordered_map<int,vector<int>>adj;
        for(auto edge:roads) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>is_visited(n+1,false);
        dfs(0,seats,is_visited,adj);
        return total_fuel;
    }
};
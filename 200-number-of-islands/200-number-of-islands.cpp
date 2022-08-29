class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y) {
            if(x<0 or x==grid.size() or y<0 or y==grid[0].size()) {
                return ;
            }
            if(grid[x][y]=='1') {
                grid[x][y]='0';
                dfs(grid,x-1,y);
                dfs(grid,x+1,y);
                dfs(grid,x,y-1);
                dfs(grid,x,y+1);
            }
        }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1') {
                    ans+=1;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(vector<vector<int>>&image,vector<vector<bool>>&visited,int curr_row,int curr_col,int src_color,int color,int m,int n) {
        if(curr_row==m or curr_row ==-1 or curr_col==n or curr_col==-1 or visited[curr_row][curr_col] or image[curr_row][curr_col]!=src_color) {
            return ;
        }
        // int curr_color=image[curr_row][curr_col];
        image[curr_row][curr_col]=color;  
        visited[curr_row][curr_col]=true;
        dfs(image,visited,curr_row+1,curr_col,src_color,color,m,n);
        dfs(image,visited,curr_row-1,curr_col,src_color,color,m,n);
        dfs(image,visited,curr_row,curr_col+1,src_color,color,m,n);
        dfs(image,visited,curr_row,curr_col-1,src_color,color,m,n);
        
          
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();//rows
        int n=image[0].size();//cols
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        dfs(image,visited,sr,sc,image[sr][sc],color,m,n);
        return image;
    }
};
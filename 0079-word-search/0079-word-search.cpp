class Solution {
public:
    void solve(int m , int n,int curr_row,int curr_col,int curr_index,string& word,vector<vector<char>>&board,vector<vector<bool>>&is_visited,bool& ans) {
        if(curr_index==word.size()) {
            ans=true;
            return;
        }
        if(curr_row==-1 or curr_row==m or curr_col==-1 or curr_col==n or is_visited[curr_row][curr_col] or ans or board[curr_row][curr_col]!=word[curr_index]) {
            return;
        }
        
        is_visited[curr_row][curr_col]=true;
        solve(m,n,curr_row,curr_col-1,curr_index+1,word,board,is_visited,ans);
        solve(m,n,curr_row,curr_col+1,curr_index+1,word,board,is_visited,ans);
        solve(m,n,curr_row+1,curr_col,curr_index+1,word,board,is_visited,ans);
        solve(m,n,curr_row-1,curr_col,curr_index+1,word,board,is_visited,ans);
        is_visited[curr_row][curr_col]=false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        bool ans=false;
        vector<vector<bool>>is_visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]==word[0]) {
                    solve(m,n,i,j,0,word,board,is_visited,ans);
                    if(ans) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
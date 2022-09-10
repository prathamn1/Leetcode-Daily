class Solution {
public:
    bool valid(vector<string>&board,int row, int col, int n ) {
        
        // I method ( simple) of checking validity just traverse the full matrix to the left of current cell and when you find the queen on a certain cell then check if our cell is being attacked by that queen or not . for checking that just see if the row of that queen is same as our cell row or if we comes in the diagonal of that queen
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<col;j++) {
                if(board[i][j]=='Q') {
                    if(i==row or (abs(i-row)==abs(j-col))) {
                        return false;
                    }
                }
            }
        }
        return true;
        
        
        // II method of checking is that there is no need to traverse the full left submatrix just check the row of the cell towards left and the diagonals of that cell both( up and down ) , if there is queen or not. # more efficient.
        // check left 
        // int x=row,y=col;
        // while(y>=0)
        // {
        //     if(board[x][y]=='Q') return false;
        //     y--;
        // }
        // x=row,y=col;
        // // digonal check 
        // while(x>=0 && y>=0)
        // {
        //     if(board[x][y]=='Q') return false;
        //     x--,y--;
        // }
        // // digonal check 
        // x=row,y=col;
        // while(x<n && y>=0)
        // {
        //     if(board[x][y]=='Q') return false;
        //     x++,y--;
        // }
        // return true;
    }

    //what we are doing is that we are keeping one queen in every column and again calling the function for the next column . if doing so we reach the end that is if we have successfully placed our queen in the n-1 th column or if our value of col becomes n then we got one of our answers as for every column we are traversing for full row so just backtrack or remove queen from that row position in that particular column and move to the next row.
    
    void solve(vector<vector<string>>&ans,vector<string>&board,int n,int col) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(valid(board,row,col,n)) {
                board[row][col]='Q';
                solve(ans,board,n,col+1);
                board[row][col]='.';// backtracking 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int col=0;
        vector<vector<string>>ans;
        solve(ans,board,n,col);
        return ans;
    }
};
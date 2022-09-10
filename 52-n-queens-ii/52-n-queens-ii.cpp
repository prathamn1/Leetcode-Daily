class Solution {
public:
    bool valid(vector<string>&board,int row, int col, int n ) {
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<col;j++) {
        //         if(board[i][j]=='Q') {
        //             if(i==row or abs(i-j)==abs(row-col)) {
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;
        
        // check left 
        int x=row,y=col;
        while(y>=0)
        {
            if(board[x][y]=='Q') return false;
            y--;
        }
        x=row,y=col;
        // digonal check 
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q') return false;
            x--,y--;
        }
        // digonal check 
        x=row,y=col;
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q') return false;
            x++,y--;
        }
        return true;
    }

    void solve(int&ans,vector<string>&board,int n,int col) {
        if(col==n) {
            ans++;
            return;
        }
        for(int row=0;row<n;row++) {
            if(valid(board,row,col,n)) {
                board[row][col]='Q';
                solve(ans,board,n,col+1);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int col=0;
        int ans=0;
        solve(ans,board,n,col);
        return ans;
    }
};
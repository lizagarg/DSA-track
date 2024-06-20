class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n) {
        //check upper diagonal
        int rowVal= row;
        int colVal= col;
        while(row>=0 && col>=0) {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        // check left
        row= rowVal;
        col=colVal;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        //lower diagonal
        row= rowVal;
        col=colVal;
        while(col>=0 && row<n) {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n) {
        //base case
        if(col==n){
            ans.push_back(board);
            return;
        }

        //for col-0, check for each row, then for col 1 and so on..
        for(int row=0; row<n; row++) {
            if(isSafe(row,col,board,n)) {
                //place it
                board[row][col]='Q';
                //check for next col
                solve(col+1, board, ans, n);
                //backtrack
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i]=s;
        }

        solve(0,board,ans,n);
        return ans;
    }
};
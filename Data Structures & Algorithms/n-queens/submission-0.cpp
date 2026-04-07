class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n){
        int tempRow = row;
        int tempCol = col;

        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }   

        row = tempRow;
        col = tempCol;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row = tempRow;
        col = tempCol;

        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;

    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board;
        for(int i=0; i<n; i++){
            board.push_back(s);
        }

        solve(0, board, ans, n);
        return ans;
    }
};

class Solution {
private:
    void dfs(int i, int j, int& r, int& c, vector<vector<bool>>& bordered, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=r || j>=c || bordered[i][j] || board[i][j]=='X') return;

        bordered[i][j] = true;

        dfs(i+1,j,r,c,bordered,board);
        dfs(i-1,j,r,c,bordered,board);
        dfs(i,j+1,r,c,bordered,board);
        dfs(i,j-1,r,c,bordered,board);

        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<bool>> bordered(r, vector<bool>(c, false));

        for(int i=0; i<r; i++){
            dfs(i, 0, r, c, bordered, board);
            dfs(i, c-1, r, c, bordered, board);
        }

        for(int j=0; j<c; j++){
            dfs(0, j, r, c, bordered, board);
            dfs(r-1, j, r, c, bordered, board);
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]=='O' && !bordered[i][j]){
                    board[i][j]='X';
                }
            }
        }

        return;
    }
};

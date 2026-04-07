class Solution {
private:
    bool solve(int idx, int r, int c, int row, int col, vector<vector<char>>& board, string& word){
        if(idx==word.size()){
            return true;
        }

        if(r<0 || c<0 || r>=row || c>=col){
            return false;
        }

        if(board[r][c]=='0') return false;

        if(board[r][c]!=word[idx]) return false;

        char temp = board[r][c];
        board[r][c]='0';

        bool output = solve(idx+1, r-1, c, row, col, board, word) ||
                       solve(idx+1, r+1, c, row, col, board, word) ||
                       solve(idx+1, r, c-1, row, col, board, word) ||
                       solve(idx+1, r, c+1, row, col, board, word);

        board[r][c]=temp;
        return output;   
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(); 
        int col=board[0].size();
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(solve(0, i, j, row, col, board, word)) return true;
            }
        }
        return false;
    }
};

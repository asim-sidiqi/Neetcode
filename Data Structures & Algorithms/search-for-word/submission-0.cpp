class Solution {
private:
    bool solve(int idx, int r, int c, int row, int col, set<pair<int,int>>& s, vector<vector<char>>& board, string& word){
        if(idx==word.size()){
            return true;
        }

        if(r<0 || c<0 || r>=row || c>=col || board[r][c]!=word[idx] || s.find({r,c})!=s.end()){
            return false;
        }

        s.insert({r,c});

        bool output = solve(idx+1, r-1, c, row, col, s, board, word) ||
                       solve(idx+1, r+1, c, row, col, s, board, word) ||
                       solve(idx+1, r, c-1, row, col, s, board, word) ||
                       solve(idx+1, r, c+1, row, col, s, board, word);

        s.erase({r,c});
        return output;   
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(); 
        int col=board[0].size();
        set<pair<int,int>> s;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(solve(0, i, j, row, col, s, board, word)) return true;
            }
        }
        return false;
    }
};

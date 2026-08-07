class Solution {
private:
    void addPair(int i, int j, int& r, int& c, vector<vector<bool>>& visited, queue<pair<int,int>>& q, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==-1 || visited[i][j]) return;

        q.push({i,j});
        visited[i][j]=true;
        return;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int,int>> q;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }

        int distance = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                grid[row][col] = distance;

                addPair(row+1,col,r,c,visited,q,grid);
                addPair(row-1,col,r,c,visited,q,grid);
                addPair(row,col+1,r,c,visited,q,grid);
                addPair(row,col-1,r,c,visited,q,grid);
            }  

            distance++;
        }
    }
};

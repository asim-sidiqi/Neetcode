class Solution {
private:
    void dfs(int i, int j, int& r, int& c, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]=='0' || visited[i][j]) return;

        visited[i][j]=true;

        dfs(i+1,j,r,c,visited,grid);
        dfs(i,j+1,r,c,visited,grid);
        dfs(i-1,j,r,c,visited,grid);
        dfs(i,j-1,r,c,visited,grid);

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j,r,c,visited,grid);
                    count++;
                }
            }
        }

        return count;
    }
};

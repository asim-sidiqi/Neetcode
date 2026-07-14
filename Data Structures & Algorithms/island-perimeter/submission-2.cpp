class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid, set<pair<int,int>>& visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return 1;
        if(visited.find({i,j})!=visited.end()) return 0;
        visited.insert({i,j});
        
        int down = dfs(i+1,j, grid, visited);
        int right = dfs(i,j+1, grid, visited);
        int up = dfs(i-1,j, grid, visited);
        int left = dfs(i,j-1, grid, visited);
        
        return up+down+left+right;        
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        set<pair<int,int>> visited;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    return dfs(i,j,grid,visited);
                }
            }
        }

        return 0;
        
    }
};
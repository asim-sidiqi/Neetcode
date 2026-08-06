class Solution {
private:
    int dfs(int i, int j, int& r, int& c, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0 || visited[i][j]) return 0;

        visited[i][j]=true;
        int count=1;

        int down = dfs(i+1,j,r,c,visited,grid);
        int up = dfs(i-1,j,r,c,visited,grid);
        int left = dfs(i,j+1,r,c,visited,grid);
        int right = dfs(i,j-1,r,c,visited,grid);

        count += down+up+left+right;

        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        int area=0;
        int maxi=INT_MIN;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!visited[i][j] || grid[i][j]==1){
                    area = dfs(i,j,r,c,visited,grid);
                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};

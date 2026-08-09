class Solution {
private:
    void dfs(int i, int j, int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights, int prevHeight){
        if(i<0 || j<0 || i>=r || j>=c || ocean[i][j] || heights[i][j] < prevHeight) return;

        ocean[i][j] = true;
        dfs(i+1,j,r,c,ocean,heights,heights[i][j]);
        dfs(i-1,j,r,c,ocean,heights,heights[i][j]);
        dfs(i,j+1,r,c,ocean,heights,heights[i][j]);
        dfs(i,j-1,r,c,ocean,heights,heights[i][j]);

        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pac(r, vector<bool>(c, false));
        vector<vector<bool>> atl(r, vector<bool>(c, false));

        for(int i=0; i<r; i++){
            dfs(i, 0, r, c, pac, heights, heights[i][0]);
            dfs(i, c-1, r, c, atl, heights, heights[i][c-1]);
        }

        for(int j=0; j<c; j++){
            dfs(0, j, r, c, pac, heights, heights[0][j]);
            dfs(r-1, j, r, c, atl, heights, heights[r-1][j]);
        }

        vector<vector<int>> ans;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(pac[i][j] && atl[i][j]){
                    vector<int> output = {i,j};
                    ans.push_back(output);
                }
            }
        }

        return ans;
    }
};
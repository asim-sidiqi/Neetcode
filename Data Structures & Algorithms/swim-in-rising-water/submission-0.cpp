class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        vector<vector<bool>> visited(row, vector<bool>(col,false));
        visited[0][0]=true;

        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            int pos = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r==row-1 && c==col-1) return pos;

            for(auto dir:directions){
                int nr = r+dir[0];
                int nc = c+dir[1];

                if(nr<0 || nc<0 || nr==row || nc==col || visited[nr][nc]) continue;
                visited[nr][nc]=true;
                pq.push({max(grid[nr][nc],pos),{nr,nc}});
            }
        }

        return -1;
    }
};

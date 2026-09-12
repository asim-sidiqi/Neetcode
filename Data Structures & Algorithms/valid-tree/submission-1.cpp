class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
            
        unordered_map<int,vector<int>> m;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            m[v].push_back(u);
            m[u].push_back(v);
        }

        vector<bool> visited(n,false);

        queue<int> q;
        q.push(0);
        visited[0]=true;

        int count=0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();

            count++;

            for(auto it:m[temp]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }

        if(count==n) return true;
        return false;
    }
};

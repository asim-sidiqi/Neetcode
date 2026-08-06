class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sz=trust.size();
        unordered_map<int,int> m;
        for(int i=0; i<sz; i++){
            m[trust[i][1]]++;
        }

        unordered_map<int,set<int>> adj;
        for(int i=0; i<sz; i++){
            int u = trust[i][0];
            int v = trust[i][1];

            adj[u].insert(v);
        }

        for(auto it:m){
            if(it.second==n-1 && adj[it.first].size()==0) return it.first; 
        }

        return -1;
    }
};
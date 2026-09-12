class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];

            m[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto it:m[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0) q.push(i);
        }

        int count=0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();

            count++;

            for(auto it:m[temp]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(count==numCourses) return true;
        return false;
    }
};

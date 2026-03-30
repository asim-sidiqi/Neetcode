class Solution {
public:

    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b){
            int d1 = a.first*a.first + a.second*a.second;
            int d2 = b.first*b.first + b.second*b.second;

            return d1 < d2; 
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto it:points){
            pair<int,int> p = {it[0],it[1]};
            pq.push(p);
            
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> ans;
        while(pq.size()!=0){
            vector<int> output;
            output.push_back(pq.top().first);
            output.push_back(pq.top().second);
            pq.pop();
            ans.push_back(output);
        }

        return ans;
    }
};

class Solution {
public:

    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b){
            int d1 = a.first*a.first + a.second*a.second;
            int d2 = b.first*b.first + b.second*b.second;

            return d1 < d2; // max heap by distance
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(auto &p : points){

            pq.push({p[0],p[1]});

            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            ans.push_back({p.first,p.second});
        }

        return ans;
    }
};
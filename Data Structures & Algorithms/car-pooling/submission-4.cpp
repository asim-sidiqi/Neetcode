class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1001,0);
        for(int i=0; i<trips.size(); i++){
            arr[trips[i][1]]+=trips[i][0];
            arr[trips[i][2]]-=trips[i][0];
        }
        int sum=0;

        for(auto it:arr){
            sum+=it;
            if(sum>capacity) return false;
        }

        return true;
        // sort(trips.begin(), trips.end(), [](vector<int> temp1, vector<int> temp2){
        //     return temp1[1]<temp2[1];
        // });

        // priority_queue<pair<int,int>> pq;
        // int sum = 0;

        // for(int i=0; i<trips.size(); i++){
        //     while(!pq.empty() && pq.top().first <= trips[i][1]){
        //         sum-=pq.top().second;
        //         pq.pop();
        //     }

        //     sum+=trips[i][0];
        //     if(sum>capacity) return false;

        //     pq.push({trips[i][2],trips[i][0]});
        // }

        // return true;
    }
};
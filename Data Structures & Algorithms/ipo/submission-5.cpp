class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>> pq;
        deque<pair<int,int>> dq;
        for(int i=0; i<profits.size(); i++){
            dq.push_back({profits[i],capital[i]});
        }

        sort(dq.begin(), dq.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second<b.second;
        });

        int currCap = w;
        while(k!=0){
            while(!dq.empty() && dq.front().second<=currCap){
                pq.push({dq.front().first,dq.front().second});
                dq.pop_front();
            }

            if(pq.empty()) return currCap;

            if(!pq.empty()){
                auto temp = pq.top();
                pq.pop();
                currCap+=temp.first;
                k--;
            }
        }

        return currCap;
    }
};
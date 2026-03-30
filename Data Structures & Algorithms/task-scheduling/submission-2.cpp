class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(auto it:tasks){
            m[it]++;
        }
        priority_queue<int> pq;
        for(auto it:m){
            pq.push(it.second);
        }

        deque<pair<int,int>> d;
        int time=0;

        while(pq.size()>0 || d.size()>0){
            time++;
            if(!pq.empty()){
                int task = pq.top();
                pq.pop();
                task--;

                if(task!=0) d.push_back({task,time+n});
            }

            if(d.size()>0 && d.front().second==time){
                pq.push(d.front().first);
                d.pop_front();
            }
        }

        return time;
    }
};

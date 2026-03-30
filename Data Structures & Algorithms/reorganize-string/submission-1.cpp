class Solution {
public:
    string reorganizeString(string s) {
        deque<pair<pair<int,char>,int>> d;
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        for(auto it:s){
            m[it]++;
        }

        for(auto it:m){
            pq.push({it.second,it.first});
        }

        string ans;
        int count=0;

        while(!pq.empty() || !d.empty()){
            count++;
            if(!pq.empty()){
                pair<int,char> temp = pq.top();
                pq.pop();

                if(!ans.empty() && ans.back() == temp.second) return "";
                ans += temp.second;

                temp.first--;

                if(temp.first!=0) d.push_back({{temp.first,temp.second},count+1});
            }

            if(d.size()>0 && d.front().second == count){
                pq.push({d.front().first.first,d.front().first.second});
                d.pop_front();
            }
        }

        // for(int i=0; i<ans.size(); i++){
        //     if(i>0 && ans[i]==ans[i-1]) return "";
        // }

        return ans; 
    }
};
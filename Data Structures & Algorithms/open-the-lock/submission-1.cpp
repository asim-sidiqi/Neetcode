class Solution {
private:
    vector<string> children(string lock){
        vector<string> ans;

        string temp;
        string digit;
        for(int i=0; i<4; i++){
            digit = to_string(((lock[i])-'0'+1)%10);
            temp = lock.substr(0,i) + digit + lock.substr(i+1);
            ans.push_back(temp);
            digit = to_string((((lock[i])-'0'-1)+10)%10);
            temp = lock.substr(0,i) + digit + lock.substr(i+1);
            ans.push_back(temp);
        }

        return ans;
    }
public:
    int openLock(vector<string>& deadends, string target) {        
        set<string> visited;
        for(auto it:deadends){
            if(it=="0000") return -1;
            visited.insert(it);
        }

        queue<pair<string,int>> q;
        int turns = 0;
        q.push({"0000",0});
        visited.insert("0000");
        while(!q.empty()){
            string lock = q.front().first;
            int turns = q.front().second;
            q.pop();

            if(lock==target) return turns;

            for(auto child: children(lock)){
                if(visited.find(child)==visited.end()){
                    q.push({child,turns+1});
                    visited.insert(child);
                }
            }
        }

        return -1;
    }
};
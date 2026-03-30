class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=tasks.size();
        vector<vector<int>> temp(n, vector<int>(3,0));
        for(int i=0; i<n; i++){
            temp[i][0]=tasks[i][0];
            temp[i][1]=tasks[i][1];
            temp[i][2]=i;
        }

        sort(temp.begin(), temp.end());
        cout<<"temp: "<<endl;
        for(auto it:temp){
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl; 
        }

        int time = temp[0][0];
        int i=0;
        vector<int> ans;

        while(!pq.empty() || i<n){
            while(i<n && time>=temp[i][0]){
                pq.push({temp[i][1],temp[i][2]});
                i++;
            }

            if(!pq.empty()){
                ans.push_back(pq.top().second);
                time+=pq.top().first;
                pq.pop();
            }

            if(i<n && time<temp[i][0]) time=temp[i][0];
        } 

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;  
    }
};
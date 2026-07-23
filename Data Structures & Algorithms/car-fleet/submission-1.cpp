class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = position.size();
        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(),cars.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first>b.first;
        }); 

        stack<float> st;

        for(auto it:cars){
            cout<<it.first<<" "<<it.second<<endl;
        }

        for(auto it:cars){
            float sp = (float)(target - it.first) / it.second;

            if(st.empty()) st.push(sp);
            else{
                if(sp>st.top()) st.push(sp);
            }
        }

        int t = st.size(); 
        while(!st.empty()){
            cout<<st.top()<<" "<<endl;
            st.pop();
        }

        return t;
    }
};

// {(8,2), (6,3)}
// 1, 1.3 
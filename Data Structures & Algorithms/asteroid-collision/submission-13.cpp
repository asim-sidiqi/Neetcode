class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto it:asteroids){
            if(st.empty()) st.push(it);
            else{
                if(it<0 && st.top()<0 || it>0 && st.top()>0 || it>0 && st.top()<0) st.push(it);
                else if(it<0 && st.top()>0){
                    while(!st.empty() && it<0 && st.top()>0 && abs(it)>abs(st.top())){
                        st.pop();
                    }
                    if(!st.empty() && it+st.top()==0){
                        st.pop();
                        continue;
                    }
                    else if(!st.empty() && it<0 && st.top()<0) st.push(it);
                    else if(st.empty()){
                        st.push(it);
                    }
                }
            }
        }

        vector<int> ans={};
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
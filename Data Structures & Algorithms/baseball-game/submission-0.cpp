class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans=0;

        for(auto it:operations){
            if(!st.empty() && it=="+"){
                int a = st.top();
                st.pop();
                int sum = a + st.top();
                st.push(a);
                st.push(sum);
            }
            else if(it=="D"){
                st.push(2*st.top());
            }
            else if(!st.empty() && it=="C") st.pop();
            else st.push(stoi(it));
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};
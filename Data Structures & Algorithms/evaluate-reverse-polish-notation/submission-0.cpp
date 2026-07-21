class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(auto it:tokens){
            if(!st.empty() && it=="+"){
                int a = st.top();
                int b=0;
                st.pop();
                if(!st.empty()) {
                    b = st.top();
                    st.pop();
                }

                st.push(a+b);
            }

            else if(!st.empty() && it=="*"){
                int a = st.top();
                int b=0;
                st.pop();
                if(!st.empty()) {
                    b = st.top();
                    st.pop();
                }

                st.push(a*b);
            }

            else if(!st.empty() && it=="-"){
                int a = st.top();
                int b=0;
                st.pop();
                if(!st.empty()) {
                    b = st.top();
                    st.pop();
                }

                st.push(b-a);
            }

            else if(!st.empty() && it=="/"){
                int a = st.top();
                int b=0;
                st.pop();
                if(!st.empty()) {
                    b = st.top();
                    st.pop();
                }

                st.push(b/a);
            }

            else st.push(stoi(it));
        }

        return st.top();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else if(it==')'){
                if(st.empty() || st.top()!='(') return false;
                else{
                    if(!st.empty()) st.pop();
                }
            }
            else if(it=='}'){
                if(st.empty() || st.top()!='{') return false;
                else{
                    if(!st.empty()) st.pop();
                }
            }
            else if(it==']'){
                if(st.empty() || st.top()!='[') return false;
                else{
                    if(!st.empty()) st.pop();
                }
            }
        }

        return st.empty();
    }
};

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string temp = "";
        stack<string> st;
        for(int i=0; i<n; i++){
            if(s[i]!=']'){
                while(i<n && s[i]!=']'){
                    st.push(string(1, s[i]));
                    i++;
                }
                i--;
            }
            else{
                while(!st.empty() && st.top()!="["){
                    temp = st.top() + temp; //instead of reverse
                    st.pop();
                }
                if(!st.empty() && st.top()=="[") st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num = st.top() + num;
                    st.pop();
                }

                int k = stoi(num);
                string decoded = "";
                for(int j=0; j<k; j++) decoded += temp;
                st.push(decoded);
                temp="";
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    } 
};
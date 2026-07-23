class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;

        int i=1;
        while(i<n){
            string temp="";
            while(i<n && path[i]=='/') i++;
            while(i<n && path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }

            if(temp=="...") st.push(temp);
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            else if(temp==".") continue;
            else st.push(temp);

            i++;
        }

        stack<string> final;
        while(!st.empty()){
            final.push(st.top());
            st.pop();
        }

        string ans="";
        ans+='/';
        while(!final.empty()){
            ans+=final.top();
            final.pop();
            if(final.size()>=1) ans+='/';
        }

        if(ans[ans.size()-1]=='/' && ans.size()>1) ans.resize(ans.size()-1);
        return ans;
    }
};
class Solution {
private:
    void solve(int o, int c, vector<string>& ans, string& output, int& n){
        if(output.size()==2*n){
            ans.push_back(output);
            return;
        }

        if(c<n || o<n){
            if(c<o){
                if(c<n){
                    output.push_back(')');
                    if(c<n) solve(o, c+1, ans, output, n);
                    output.pop_back();
                }
                if(o<n){
                    output.push_back('(');
                    if(o<n) solve(o+1, c, ans, output, n);
                    output.pop_back();
                }
            }
            else{
                output.push_back('(');
                if(o<n) solve(o+1, c, ans, output, n);
                output.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        solve(0, 0, ans, output, n);
        return ans;
    }
};

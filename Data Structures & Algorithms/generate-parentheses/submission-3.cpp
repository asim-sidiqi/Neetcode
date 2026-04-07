class Solution {
private:
    void solve(int o, int c, vector<string>& ans, string& output, int& n){
        if(output.size()==2*n){
            ans.push_back(output);
            return;
        }

        if(o<n){
            output.push_back('(');
            solve(o+1, c, ans, output, n);
            output.pop_back();
        }

        if(c<o){
            output.push_back(')');
            solve(o, c+1, ans, output, n);
            output.pop_back();
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

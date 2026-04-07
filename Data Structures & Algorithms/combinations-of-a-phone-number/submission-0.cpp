class Solution {
private:
    void solve(int idx, string& digits, vector<string>& ans, string& output, unordered_map<char,string>& m){
        if(output.size()==digits.size()){
            ans.push_back(output);
            return;
        }

        for(int i=0; i<m[digits[idx]].size(); i++){
            output.push_back(m[digits[idx]][i]);
            solve(idx+1, digits, ans, output, m);
            output.pop_back();
        }   
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz"; 

        vector<string> ans;
        if(digits.size()==0) return ans;
        string output;
        solve(0, digits, ans, output, m);
        return ans;
    }
};

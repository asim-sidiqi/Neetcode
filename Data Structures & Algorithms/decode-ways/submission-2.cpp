class Solution {
private:
    int solve(int idx, int& n, string& s, unordered_map<string,int>& m, vector<int>& dp){
        if(idx>n) return 0;
        if(idx==n) return 1;

        if(dp[idx]!=-1) return dp[idx];

        int l=0, r=0;
        if(m[s.substr(idx,1)]){
            l = solve(idx+1, n, s, m, dp);
        }
        if(m[s.substr(idx,2)]){
            r = solve(idx+2, n, s, m, dp);
        }

        return dp[idx] = l+r;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        unordered_map<string,int> m;
        for(int i=1; i<=26; i++){
            m[to_string(i)]= 1;
        }

        vector<int> dp(n,-1);

        return solve(0, n, s, m, dp);
    }
};

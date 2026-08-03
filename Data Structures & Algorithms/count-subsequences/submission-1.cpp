class Solution {
private:
    int solve(int idx1, int idx2, int& n, int& m, string& s, string& t, vector<vector<int>>& dp){
        if(idx1==n && idx2<m) return 0;
        if(idx2==m) return 1;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        int ans = 0;
        if(s[idx1]==t[idx2]){
            ans = solve(idx1+1, idx2+1, n, m, s, t, dp) + solve(idx1+1, idx2, n, m, s, t, dp);
        }
        else{
            ans = solve(idx1+1, idx2, n, m, s, t, dp);
        }

        return dp[idx1][idx2] = ans;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(0, 0 , n, m, s, t, dp);
    }
};

class Solution {
private:
    bool solve(int idx1, int idx2, int& n, int& m, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        if(idx1==n && idx2==m) return true;
        
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        bool ans = false;
        if(s1[idx1]==s3[idx1+idx2]) ans |= solve(idx1+1, idx2, n,m,s1,s2,s3, dp);
        if(s2[idx2]==s3[idx1+idx2]) ans |= solve(idx1, idx2+1, n,m,s1,s2,s3, dp);

        return dp[idx1][idx2] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();

        if(n+m!=o) return false;

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(0,0,n,m, s1, s2, s3, dp);
    }
};
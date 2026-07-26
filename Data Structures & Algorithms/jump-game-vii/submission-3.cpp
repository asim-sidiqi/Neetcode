class Solution {
private:
    bool solve(int idx, int& n, string& s, int& mi, int& ma, vector<int>& dp){
        if(idx>=n) return false;
        if(idx==n-1 && s[idx]=='0') return true;

        if(dp[idx]!=-1) return dp[idx];

        for(int i=mi; i<=ma; i++){
            if(idx+i<n && s[idx+i]=='0' && solve(idx+i, n, s, mi, ma, dp)){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, s, minJump, maxJump, dp);
    }
};
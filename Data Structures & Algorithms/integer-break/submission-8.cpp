class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n<=0) return 1;

        if(dp[n]!=-1) return dp[n];

        int maxi = INT_MIN;
        for(int i=1; i<n; i++){
            int l = i*(n-i);    //dont break it further
            int r = i*solve(n-i,dp); //break it further
            maxi = max(maxi,max(l,r));
        }

        return dp[n] = maxi;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
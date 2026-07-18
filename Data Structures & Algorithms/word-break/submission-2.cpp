class Solution {
private:
    bool solve(int idx, int n, string& s, vector<string>& wordDict, vector<int>& dp){
        if(idx>=n) return true;

        if(dp[idx]!=-1) return dp[idx];
        string temp;
        bool l = false;
        for(int i=1; idx+i<=n; i++){
            temp=s.substr(idx,i);

            if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()){
                l = solve(idx+i, n, s, wordDict, dp);
            }

            if(l==true) return dp[idx] = true;
        }

        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return solve(0,s.size(),s,wordDict,dp);
    }
};



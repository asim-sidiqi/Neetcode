class Solution {
private:
    int solve(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp){
        if(idx1 < 0) return idx2 + 1;
        if(idx2 < 0) return idx1 + 1;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        int temp=0;

        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2] = solve(idx1-1, idx2-1, text1, text2, dp);
        }

        else{
            temp = min(solve(idx1-1, idx2-1, text1, text2, dp), min(solve(idx1-1, idx2, text1, text2, dp), solve(idx1, idx2-1, text1, text2, dp)));

            return dp[idx1][idx2] = 1 + temp;
        }

        return 0;
    }    
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(n1-1, n2-1, word1, word2, dp);
    }
};

// neatcdee
// neetcode
// netcde

// horse 
// ros


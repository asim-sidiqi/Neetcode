class Solution {
private:
    bool solve(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx>=n) return false;
        if(idx==n-1) return true;

        if(dp[idx]!=-1) return dp[idx];

        bool temp=false;
        for(int i=1; i<=nums[idx]; i++){
            temp = solve(idx+i, n, nums, dp) || temp;
        }

        return dp[idx] = temp;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp);
    }
};

class Solution {
private:
    int solve(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx>=n) return 0;
        if(idx==n-1) return 1;

        if(dp[idx]!=-1) return dp[idx];

        int mini = INT_MAX;
        for(int i=1; i<=nums[idx]; i++){
            if(solve(idx+i, n, nums, dp)>0){
                mini = min(mini,solve(idx+i, n, nums, dp));
            }
        }

        return dp[idx] = 1+mini;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp)-1;
    }
};

class Solution {
private:
    int solve(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx>=n-1){
            return 0;
        }

        if(dp[idx]!=-1) return dp[idx];

        int l = solve(idx+1, n, nums, dp);
        int r = nums[idx] + solve(idx+2, n, nums, dp);

        return dp[idx] = max(l,r);
    }

    int solve2(int idx, int n, vector<int>& nums, vector<int>& dp2){
        if(idx>=n){
            return 0;
        }

        if(dp2[idx]!=-1) return dp2[idx];

        int l = solve2(idx+1, n, nums, dp2);
        int r = nums[idx] + solve2(idx+2, n, nums, dp2);

        return dp2[idx] = max(l,r);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        vector<int> dp2(n+1,-1);
        if(n==1) return nums[0];
        return max(solve(0, n, nums, dp), solve2(1, n, nums, dp2));
    }
};

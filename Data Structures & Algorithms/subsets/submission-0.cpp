class Solution {
private:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& output){
        if(idx==nums.size()){
            ans.push_back(output);
            return;
        }

        output.push_back(nums[idx]);
        solve(idx+1, nums, ans, output);
        output.pop_back();
        solve(idx+1, nums, ans, output);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, nums, ans, output);
        return ans;
    }
};

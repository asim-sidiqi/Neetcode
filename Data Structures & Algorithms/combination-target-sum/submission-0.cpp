class Solution {
private:
    void solve(int index, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& output){
        if(index==nums.size()){
            if(target==0){
                ans.push_back(output);
            }
            return;
        }

        if(nums[index]<=target){
            output.push_back(nums[index]);
            solve(index, nums, target-nums[index], ans, output);
            output.pop_back();
        }

        solve(index+1, nums, target, ans, output);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, nums, target, ans, output);
        return ans;
    }
};

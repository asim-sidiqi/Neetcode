class Solution {
private:
    void solve(int idx, vector<int>& nums, set<vector<int>>& ans, vector<int>& output){
        if(idx==nums.size()){
            sort(output.begin(), output.end());
            ans.insert(output);
            return;
        }

        output.push_back(nums[idx]);
        solve(idx+1, nums, ans, output);
        output.pop_back();
        solve(idx+1, nums, ans, output);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(),nums.end());
        solve(0, nums, ans, output);
        vector<vector<int>> temp;
        for(auto it:ans){
            temp.push_back(it);
        }
        return temp;
    }
};

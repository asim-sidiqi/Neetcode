class Solution {
private:
    void solve(int idx, vector<int>& nums, set<vector<int>>& ans){
        if(idx==nums.size()){
            ans.insert(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            solve(idx+1, nums, ans);
            swap(nums[idx],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(0, nums, ans);

        vector<vector<int>> temp;
        for(auto it:ans){
            temp.push_back(it);
        }

        return temp;
    }
};

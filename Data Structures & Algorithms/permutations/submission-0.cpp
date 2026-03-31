class Solution {
private:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, unordered_map<int,bool>& m){
        if(output.size()==nums.size()){
            ans.push_back(output);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!m[nums[i]]){
                output.push_back(nums[i]);
                m[nums[i]]=true;
                solve(i+1, nums, ans, output, m);
                output.pop_back();
                m[nums[i]]=false;
            }
 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        unordered_map<int,bool> m;
        solve(0, nums, ans, output, m);
        return ans;
    }
};

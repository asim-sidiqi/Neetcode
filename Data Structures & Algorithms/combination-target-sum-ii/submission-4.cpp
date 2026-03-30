class Solution {
private:
    void solve(int idx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& output){
        if(target==0){
            ans.push_back(output);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            output.push_back(candidates[i]);
            solve(i+1, target-candidates[i], candidates, ans, output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, target, candidates, ans, output);
        return ans;
    }
};

class Solution {
private:
    void solve(int idx, vector<int>& arr, int k, vector<vector<int>>& ans, vector<int>& output){
        if(k==0){
            ans.push_back(output);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            output.push_back(arr[i]);
            solve(i+1, arr, k-1, ans, output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> output;
        solve(0, arr, k, ans, output);
        return ans;
    }
};
class Solution {
private:
    void solve(int idx, vector<int>& arr, int k, vector<vector<int>>& ans, vector<int>& output){
        if(k==0){
            ans.push_back(output);
            return;
        }

        if(idx<arr.size()){
            output.push_back(arr[idx]);
            solve(idx+1, arr, k-1, ans, output);
            output.pop_back();
            solve(idx+1, arr, k, ans, output);
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
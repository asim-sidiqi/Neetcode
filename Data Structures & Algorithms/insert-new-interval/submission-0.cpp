class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int maxi = INT_MIN;
        vector<vector<int>> ans;
        vector<int> output(2,-1);
        for(int i=0; i<n; i++){
            int j =i+1;
            maxi = intervals[i][1];
            while(j<n && maxi>=intervals[j][0]){
                maxi= max(maxi,intervals[j][1]);
                j++;
            }

            output[0]=intervals[i][0];
            output[1]=maxi;
            ans.push_back(output);
            i=j-1;
        }

        return ans;
    }
};

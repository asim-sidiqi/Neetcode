class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();
        int area;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                area = min(heights[i],heights[j])*(j-i);
                maxi = max(maxi,area);
            }
        }

        return maxi;
    }
};

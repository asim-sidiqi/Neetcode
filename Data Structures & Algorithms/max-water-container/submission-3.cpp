class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int maxi = INT_MIN;
        int area;
        while(l<=r){
            maxi = max(maxi,min(heights[l],heights[r])*(r-l));
            if(heights[l]<heights[r]) l++;
            else r--;
        }

        return maxi;
    }
};

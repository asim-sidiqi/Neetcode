class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int maxi = INT_MIN;
        int area;
        while(l<=r){
            area = min(heights[l],heights[r])*(r-l);
            maxi=max(maxi,area);
            if(heights[l]<heights[r]) l++;
            else r--;
        }

        return maxi;
    }
};

class Solution {
private:
    vector<int> nseMaker(vector<int>& heights, bool strict) {
        int n = heights.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                  (strict ? heights[st.top()] >= heights[i]
                          : heights[st.top()] > heights[i])) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // NSE: next strictly smaller
        vector<int> nse = nseMaker(heights, true);

        reverse(heights.begin(), heights.end());

        vector<int> pse = nseMaker(heights, false);

        reverse(heights.begin(), heights.end());

        for (int i = 0; i < n; i++)
            pse[i] = n - 1 - pse[i];

        reverse(pse.begin(), pse.end());

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxi = max(maxi, heights[i] * width);
        }

        return maxi;
    }
};
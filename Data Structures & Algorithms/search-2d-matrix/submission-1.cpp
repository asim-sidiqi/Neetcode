class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
                int n = matrix.size(), m=matrix[0].size();
                int l=0, r=n*m-1;
                int mid = l+(r-l)/2;

                while(l<=r){
                    if(matrix[mid/m][mid%m]==target) return true;

                    else if(matrix[mid/m][mid%m]<target) l=mid+1;

                    else r=mid-1;

                    mid=l+(r-l)/2;
                }

                return false;
        }
};
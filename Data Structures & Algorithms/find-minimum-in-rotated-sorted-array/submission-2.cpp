class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0, r=n-1;
        int mid = l+ (r-l)/2;
        while(l<=r){
            if(mid>0 && mid<n-1 && nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]) return nums[mid];

            else if(nums[0]<=nums[mid] && nums[n-1]<nums[mid]) l=mid+1;

            else r=mid-1;

            mid=l+(r-l)/2;
        }

        return nums[l];
    }
};

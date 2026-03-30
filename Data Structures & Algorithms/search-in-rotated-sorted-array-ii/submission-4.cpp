class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid = l + (r - l) / 2;

        while(l<=r){
            if(nums[mid]==target) return true;

            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++;
                r--;
            }

            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            else{
                if(nums[r]>=target && target>nums[mid]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            mid = l + (r - l) / 2;
        }
        return false;
    }
};

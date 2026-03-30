class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int check = 0;
        int count = 0;
        while(l<n){
            r = l;
            while(r<n){
                check += nums[r];
                if(check == k) count++;
                r++;
            }
            l++;
            check = 0;
        }

        return count;
    }
};
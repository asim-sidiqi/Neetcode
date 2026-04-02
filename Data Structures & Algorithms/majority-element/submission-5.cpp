class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem;
        int count=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(count==0) elem = nums[i];
            if(nums[i]==elem) count++;
            else count--;
        }

        count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==elem) count++;
        }

        if(count<=n/2) return -1;

        return elem;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0) elem = nums[i];
            if(nums[i]==elem) count++;
            else count--;
        }

        return elem;
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        vector<int> ans(nums.size(),0);
        for(int &it:nums){
            if(it!=val) count++;
        }

        auto new_end = remove(nums.begin(), nums.end(), val);

        nums.erase(new_end, nums.end());

        return count;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for(auto it:nums){
            t = t^it;
        }

        return t;
    }
};

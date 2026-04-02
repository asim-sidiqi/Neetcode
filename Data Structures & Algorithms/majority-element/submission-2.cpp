class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int it:nums){
            m[it]++;
            if(m[it]>n/2) return it;
        }

        return -1;
    }
};
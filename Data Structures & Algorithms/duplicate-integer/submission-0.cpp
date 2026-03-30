class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool ans=false;
        unordered_map<int,int> m(nums.size());
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]]==2){
                ans=true;
                break;
            }
        }

        return ans;
    }
};
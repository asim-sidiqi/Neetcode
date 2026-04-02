class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> ans;
        for(int it:nums){
            m[it]++;
        }

        for(auto it:m){
            if(it.second>(n/3)) ans.push_back(it.first);
        }

        return ans;
    }
};
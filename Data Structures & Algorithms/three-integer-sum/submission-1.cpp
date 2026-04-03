class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    while(nums[k]==nums[k-1]) k--;
                    k--;
                    while(nums[j]==nums[j+1]) j++;
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    while(nums[k]==nums[k-1]) k--;
                    k--;
                }
                else{
                    while(nums[j]==nums[j+1]) j++;
                    j++;
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

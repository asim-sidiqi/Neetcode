class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[k]==nums[k-1]) k--;
                    k--;
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    while(j<k && nums[k]==nums[k-1]) k--;
                    k--;
                }
                else{
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                }
            }
        }

        return ans;
    }
};

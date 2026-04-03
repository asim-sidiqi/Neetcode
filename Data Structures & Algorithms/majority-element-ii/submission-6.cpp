class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int elem1 = INT_MIN;
        int elem2 = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(count1 == 0 && nums[i]!=elem2){
                count1 = 1;
                elem1 = nums[i];
            }
            else if(count2 == 0 && nums[i]!=elem1){
                count2 = 1;
                elem2 = nums[i];
            }
            else if(nums[i]==elem1) count1++;
            else if(nums[i]==elem2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==elem1) count1++;
            if(nums[i]==elem2) count2++;
        }

        if(count1>n/3) ans.push_back(elem1);
        if(count2>n/3) ans.push_back(elem2);
        return ans;
    }
};
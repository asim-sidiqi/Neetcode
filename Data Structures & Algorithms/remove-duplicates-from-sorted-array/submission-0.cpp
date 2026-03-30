class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=nums.size()-1;

        while(i<=j){
            if(i>0 && nums[i]==nums[i-1]){
                for(int k=i; k<j; k++){
                    nums[k]=nums[k+1];
                }
                nums.resize(nums.size()-1);
                j=nums.size()-1;
                i--;
            } 

            i++;
        }

        return nums.size();
    }
};
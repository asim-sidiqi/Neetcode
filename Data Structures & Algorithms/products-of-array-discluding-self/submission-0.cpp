class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int &it:nums){
            m[it]++;
        }

        vector<int> output(n,0);

        if(m[0]>1){
            return output;
        }

        else if(m[0]==1){
            int prod = 1;
            int idx;
            for(int i=0; i<n; i++){
                if(nums[i]!=0) prod*=nums[i];
                if(nums[i]==0) idx=i;
            }

            output[idx] = prod;
            return output;
        }

        else{
            int prod = 1;
            for(int i=0; i<n; i++){
                prod*=nums[i];
            }

            for(int i=0; i<n; i++){
                output[i]=prod/nums[i];
            }

            return output;
        }

        return output;
    }
};

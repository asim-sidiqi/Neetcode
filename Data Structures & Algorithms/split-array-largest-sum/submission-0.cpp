class Solution {
private:
    bool solve(vector<int>& nums, int mid, int k){
        int studCount=0, pageCount=0, i=0;
        while(i<nums.size()){
            if(nums[i]+pageCount<=mid){
                pageCount+=nums[i];
            }
            else{
                studCount++;
                if(studCount>k) return false;
                if(studCount==k && i!=nums.size()) return false;
                pageCount=0;
                i--;
            } 
            i++;
        }

        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int r = 0;
        for(auto &it: nums){
            r+=it;
        }
        int l=0;

        int mid = l+(r-l)/2;

        while(l<=r){
            if(solve(nums,mid,k)) r=mid-1;

            else l=mid+1;

            mid = l+(r-l)/2;
        }
        
        return l;
    }
};
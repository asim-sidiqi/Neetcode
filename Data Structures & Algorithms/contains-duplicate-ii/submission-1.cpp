class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==1) return false;
        unordered_map<int,int> m;
        int i=0, j=k;
        for(int x=i; x<=j; x++){
            m[nums[x]]++;
            if(m[nums[x]]>1) return true;
        }

        while(j<nums.size()){
            m[nums[i]]--;
            i++;
            j++;
            if(j<nums.size())  m[nums[j]]++;
            if(j<nums.size() && m[nums[j]]>1) return true;
        }

        return false;
    }
};
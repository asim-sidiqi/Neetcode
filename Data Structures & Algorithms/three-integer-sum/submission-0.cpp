class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,bool> m;
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(m.find(-(nums[i]+nums[j]))!=m.end()){
                    vector<int> output;
                    output.push_back(nums[i]);
                    output.push_back(nums[j]);
                    output.push_back(-(nums[i]+nums[j]));
                    sort(output.begin(),output.end());
                    st.insert(output);
                }

                m[nums[j]]=true;
            }

            m.clear();
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

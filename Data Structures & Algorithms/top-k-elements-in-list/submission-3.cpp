class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m; 
        int n = nums.size(); 
        for(auto &it:nums){ 
            m[it]++; 
        } 
        vector<int> freq; 
        for(auto it:m){ 
            freq.push_back(it.second); 
        } 
        vector<int> output; 
        sort(freq.begin(),freq.end()); 
        for(int i=0; i<k;){ 
            for(auto it:m){ 
                if(it.second==freq[freq.size()-i-1] && i<k){ 
                    output.push_back(it.first); 
                    i++; 
                } 
            } 
        } 
        return output;
    }
};

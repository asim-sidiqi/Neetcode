class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> check(strs.size(),false);
        int i=0;
        while(i<strs.size()){
            vector<string> output;
            string s1 = strs[i];
            check[i]=true;
            output.push_back(strs[i]);

            for(int j=i+1; j<strs.size(); j++){
                string t1 = strs[j];

                sort(s1.begin(), s1.end());
                sort(t1.begin(), t1.end());

                if(s1==t1){
                    check[j]=true;
                    output.push_back(strs[j]);
                }
            }

            ans.push_back(output);
            while(check[i]!=false) i++;
        }

        return ans;
    }
};

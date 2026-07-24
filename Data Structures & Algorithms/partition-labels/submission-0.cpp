class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char,int> m;
        for(int i=0; i<n; i++){
            m[s[i]] = i;
        }

        for(auto it:m){
            cout<<it.first<<":"<<it.second<<endl;
        }

        int last = 0;
        for(int i=0; i<n; i++){
            last = m[s[i]];
            cout<<last<<endl;
            for(int j=i; j<=last; j++){
                last = max(last,m[s[j]]);
            }

            ans.push_back(last-i+1);
            i=last;
        }

        return ans;
    }
};

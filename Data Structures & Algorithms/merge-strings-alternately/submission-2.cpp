class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m=word2.size();
        int l=0, r=0;
        string ans;
        while(l<n && r<m){
            ans+=word1[l];
            ans+=word2[r];
            l++; r++;
        }

        while(l<n){
            ans+=word1[l];
            l++;
        }
        while(r<m){
            ans+=word2[r]; 
            r++;
        }

        return ans;
    }
};
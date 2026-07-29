class Solution {
private:
    bool sorted(string a, string b, unordered_map<char,int>& m){
        int t = min(a.size(),b.size());

        for (int i = 0; i < t; i++) {
            if (a[i] == b[i]) continue;

            return m[a[i]] < m[b[i]];
        }

        return a.size() <= b.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=order.size();
        int sz=words.size();
        unordered_map<char,int> m;
        for(int i=0; i<n; i++){
            m[order[i]]=i;
        }

        for(int i=0; i+1<sz; i++){
            if(!sorted(words[i],words[i+1],m)) return false;
        }
        return true;
    }
};
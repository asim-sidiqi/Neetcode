class Solution {
private:
    bool solve(int idx1, int idx2, int& n, int& m, string& s1, string& s2, string& s3){
        if(idx1==n && idx2==m) return true;
        
        bool ans = false;
        if(s1[idx1]==s3[idx1+idx2]) ans |= solve(idx1+1, idx2, n,m,s1,s2,s3);
        if(s2[idx2]==s3[idx1+idx2]) ans |= solve(idx1, idx2+1, n,m,s1,s2,s3);

        return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();

        if(n+m!=o) return false;
        
        return solve(0,0,n,m, s1, s2, s3);
    }
};
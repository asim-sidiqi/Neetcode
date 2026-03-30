class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(n!=1){
            int sum=0;
            string x = to_string(n);
            for(auto it:x){
                int t = it-'0';
                sum+=t*t;
            }

            if(m[sum]==1) return false;
            n=sum;
            m[n]=1;
        }

        return true;
    }
};

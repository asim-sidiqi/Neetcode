class Solution {
public:
    int mySqrt(int x) {
        long long l=0, r=x;
        long long mid = l+(r-l)/2;
        int ans;
        while(l<=r){
            if((mid*mid)==x) return mid;

            else if((mid*mid)<x){
                ans=mid;
                l=mid+1;
            }

            else r=mid-1;

            mid = l+(r-l)/2;
        }
        return ans;
    }
};
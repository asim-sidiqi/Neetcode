class Solution {
private:
    long long calculateHours(vector<int>& piles, int k){
        long long count = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]<=k) count++;
            else{
                count+=(piles[i]/k);
                if(piles[i]%k!=0) count++;
            }
        }
        
        return count;  
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        
        int l=1, r=piles[piles.size()-1];
        int mid = l+(r-l)/2;
        while(l<=r){
            if(calculateHours(piles,mid)<=h){
                r=mid-1;
            }

            else{
                l=mid+1;
            }

            mid = l+(r-l)/2;
        }

        return l;
    }
};

class Solution {
private: 
        int isShipped(vector<int>& weights, int n, int mid){ 
                int daysReq = 0; int i=0; int sum=0; 
                while(i<=n){ 
                    if(i<n && weights[i]>mid) return INT_MAX;
                    if(sum>=mid){ 
                        daysReq++; 
                        if(sum!=mid) i--; 
                        if(i<n) sum=0; 
                    } 
                    if(i<n) sum+=weights[i]; 
                    i++; 
                } 

                if(sum<mid) daysReq++;
                cout<<daysReq<<endl;
                return daysReq; 
        }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(); 
        int sum = 0; 
        for(int it:weights){ 
                sum+=it; 
        } 
        int l=1, r=sum; 
        int mid = l+(r-l)/2; 
        while(l<=r){ 
            if(isShipped(weights, n, mid)<=days) r=mid-1; 
            else l=mid+1; 
            mid= l+(r-l)/2; 
        } 
        return l;
    }
};
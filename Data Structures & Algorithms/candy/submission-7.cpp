class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum=0;
        if(ratings.size()==1) return 1;
        vector<int> ans(n,1);
        int count=1;
        int i=0, j=0;
        while(i<n){
            if(i+1<n && ratings[i]>ratings[i+1]){
                j=i;
                count=1;
                while(j+1<n && ratings[j]>ratings[j+1]){
                    count++;
                    j++;
                }

                if(i>0 && count<=ans[i-1] && ratings[i]!=ratings[i-1]){
                    count--;
                    i++;
                }

                while(count>1){
                    ans[i]=count;
                    count--;
                    i++;
                }
                
            }
            else if(i+1<n && ratings[i]<ratings[i+1]){
                count=1;
                while(i+1<n && ratings[i]<ratings[i+1]){
                    ans[i]=count;
                    i++;
                    count++;
                }
                ans[i]=ans[i-1]+1;
            }
            else i++;
        }
        
        if(ratings[n-1]>ratings[n-2]) ans[n-1]=ans[n-2]+1;
        for(auto it:ans){
            cout<<it<<" ";
            sum+=it;
        }

        return sum;
    }
};
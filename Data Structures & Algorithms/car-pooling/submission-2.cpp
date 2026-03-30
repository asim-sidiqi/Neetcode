class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int> temp, vector<int> temp2){
            return temp[1]<temp2[1];
        });
        int sum =0;
        int point=trips[0][2];;

        for(int i=0; i<trips.size(); i++){
            if(sum>capacity) return false;

            sum+=trips[i][0];

            
            if(i!=0 && trips[i][1]>=point){
                sum=trips[i][0];
            } 
        
            point=trips[i][2];  
        }

        if(sum>capacity) return false;
        return true;
    }
};
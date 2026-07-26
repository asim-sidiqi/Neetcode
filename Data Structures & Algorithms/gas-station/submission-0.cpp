class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int sum = 0;
        int i=0;
        int currGas = 0;
        int fail = 0;
        while(sum<n){ 
            if(cost[i]>gas[i]+currGas){
                i++;
                ans = i;
                sum=0;
                fail++;
                currGas=0;
            }
            else{
                currGas+= (gas[i]-cost[i]);
                i++;
                sum++;
            }
            if(fail == n) {
                return -1;
            }
            if(i==n) i=0;
        }
        return ans; 
    }
};

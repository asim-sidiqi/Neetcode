class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twens = 0;
        bool ans = true;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                fives++;
            }
            else if(bills[i]==10){
                tens++;
                fives--;
            }
            else{
                twens++;
                if(tens>0){
                    tens--;
                    fives--;
                }
                else{
                    fives--;
                    fives--;
                    fives--;
                }
            }

            if(fives<0 || tens<0) return false;
        }

        return true;
    }
};
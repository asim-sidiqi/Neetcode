class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int,int> m;

        for(int card : hand){
            m[card]++;
        }

        for(auto it = m.begin(); it != m.end(); ++it){
            int start = it->first;
            int freq = it->second;

            if(freq > 0){
                for(int i = 0; i < groupSize; i++){
                    if(m[start + i] < freq)
                        return false;

                    m[start + i] -= freq;
                }
            }
        }

        return true;
    }
};
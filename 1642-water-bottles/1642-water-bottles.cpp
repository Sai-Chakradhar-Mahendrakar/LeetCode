class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;

        float full = numBottles;
        while((int)full>0){
            full = (float)numBottles/numExchange;
            int rem = numBottles%numExchange;
            sum+=(int)full;
            numBottles = (int)full+rem;
        }
        return sum;
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0;
        int c10=0;

        for(auto x:bills){
            if(x==5){
                c5++;
            }
            else if(x==10 && c5>=1){
                c10++;
                c5--;
            }
            else if(x==20 && c10>=1 && c5>=1){
                c10--;
                c5--;
            }
            else if(x==20 && c5>=3){
                c5-=3;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
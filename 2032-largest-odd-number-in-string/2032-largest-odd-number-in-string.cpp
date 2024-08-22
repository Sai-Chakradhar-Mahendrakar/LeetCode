class Solution {
public:
    string largestOddNumber(string num) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n=num.size();
        if((num[n-1]-'0')%2){
            return num;
        }
        
        for(int i=n-2;i>=0;i--){
            int digit = num[i]-'0';
            if(digit%2){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
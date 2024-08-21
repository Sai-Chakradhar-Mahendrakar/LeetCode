class Solution {
public:
    int calculate(string s) {
        int num=0;
        int res=0;
        int signVal=1;
        stack<int> op;

        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(isdigit(ch)){
                num = num*10+(ch-'0');
            }
            else if(ch=='+' or ch=='-'){
                res += num*signVal;
                signVal = (ch=='-')?-1:1;
                num=0;
            }
            else if(ch=='('){
                op.push(res);
                op.push(signVal);
                res=0;
                signVal=1;
            }
            else if(ch==')'){
                res+=signVal*num;
                res*=op.top();
                op.pop();
                res+=op.top();
                op.pop();
                num=0;
            }
        }
        return res+num*signVal;
    }
};
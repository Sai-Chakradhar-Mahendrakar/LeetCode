class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(auto x:logs){
            if(x=="../"){
                if(cnt!=0){
                    cnt--;
                }
            }else if(x=="./"){
                continue;
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};
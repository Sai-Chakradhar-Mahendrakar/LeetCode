class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(num, target, res, 0, "", 0, 0);
        return res;
    }
private:
    void backtrack(string num, int target, vector<string>& res, int i, string numPath, long sum, long prev){
        if(i==num.size()){
            if(sum==target){
                res.push_back(numPath);
            }
            return;
        }

        for(int j=i;j<num.size();j++){
            if(j>i && num[i]=='0'){
                break;
            }

            long number = stol(num.substr(i, j-i+1));
            string tempPath=num.substr(i, j-i+1);
            
            if(i==0){
                backtrack(num, target, res, j+1, tempPath, number, number);
            }
            else{
                backtrack(num, target, res, j+1, numPath+'+'+tempPath, sum+number, number);
                backtrack(num, target, res, j+1, numPath+'-'+tempPath, sum-number, -number);
                backtrack(num, target, res, j+1, numPath+'*'+tempPath, sum-prev+(prev*number), prev*number);
            }
        }
    }
};
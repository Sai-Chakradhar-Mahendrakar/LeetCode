class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

	    if(digits.empty()){
	    	return res;
	    }

	    printKey(digits, "", res, 0);
	    return res;
    }
private:
    string keypad[10] = {"", "", "abc",  "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"};
    
    void printKey(string ip, string op, vector<string>& res, int i){
        if(i==ip.size()){
            res.push_back(op);
            return;
        }

        int curDig = ip[i]-'0';
        if(curDig==0 || curDig==1){
            printKey(ip, op, res, i+1);
            return;
        }

        for(int k=0;k<keypad[curDig].size();k++){
            printKey(ip, op+keypad[curDig][k], res, i+1);
        }
    }
};
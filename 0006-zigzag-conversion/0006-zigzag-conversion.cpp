class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        vector<string> str(numRows, "");
        int dir=-1;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j==numRows-1 or j==0){
                dir*=(-1);
            }
            str[j]+=s[i];
            
            if(dir==1){
                j++;
            }
            else{
                j--;
            }
        }

        string res;
        for(auto it : str){
            res += it; 
        }
        return res;
    }
};
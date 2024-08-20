class Solution {
public:
    bool wordPattern(string pattern, string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        stringstream ss(s);
        string word;
        unordered_map<string, char>mps;
        unordered_map<char, char>mpp;

        string sstr="";
        string pstr="";

        char ch = 'a';

        while(ss >> word){
            if(mps.find(word)==mps.end()){
                mps[word]=ch++;
            }
            sstr+=mps[word];
        }

        ch = 'a';

        for(auto it:pattern){
            if(mpp.find(it)==mpp.end()){
                mpp[it]=ch++;
            }
            pstr+=mpp[it];
        }

        if(sstr==pstr){
            return true;
        }
        
        return false;
    }
};
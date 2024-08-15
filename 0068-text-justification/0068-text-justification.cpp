class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cur=0,oglen=0;
        vector<string> aux;

        for(string s:words){
            int l=s.length();

            if(maxWidth-cur>l){
                cur+=s.length()+1;
                oglen+=s.length();
                aux.push_back(s);
            }
            else if(maxWidth-cur==l){
                cur+=s.length();
                oglen+=s.length();
                aux.push_back(s);
            }
            else{
                cur=0;
                string help="";
                int totSpace = maxWidth-oglen;

                oglen=0;
                int pos=aux.size()-1;

                for(auto x:aux){
                    int spaces=0;
                    if(pos!=0){
                        spaces = (ceil)(totSpace*1.00/pos);
                    }
                    string sp="";
                    for(int i=0;i<spaces;i++){
                        sp+=" ";
                    }
                    help+=x+sp;
                    totSpace-=spaces;
                    pos--;
                }
                aux.clear();
                help=help.substr(0, maxWidth);
                int extra=maxWidth-help.length();
                for(int i=0;i<extra;i++){
                    help+=" ";
                }
                res.push_back(help);

                aux.push_back(s);
                cur+=s.length()+1;
                oglen+=s.length();
            }
        }

        string help="";
        for(auto x:aux){
            help+=x+" ";
        }

        int spaces = maxWidth-help.length();
        for(int i=0;i<spaces;i++){
            help+=" ";
        }
        help=help.substr(0, maxWidth);
        res.push_back(help);
        return res;
    }
};
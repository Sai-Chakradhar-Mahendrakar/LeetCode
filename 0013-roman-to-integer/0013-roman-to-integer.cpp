class Solution {
public:
    int romanToInt(string s) {
        int r=0;
        char d='O';
        for(auto c:s){
            if(c=='I'){
                r+=1;
            }
            else if(c=='V' && d!='I'){
                r+=5;
            }
            else if(c=='V' && d=='I'){
                r-=1;
                r+=4;
            }
            else if(c=='X' && d!='I'){
                r+=10;
            }
            else if(c=='X' && d=='I'){
                r-=1;
                r+=9;
            }
            else if(c=='L' && d!='X'){
                r+=50;
            }
            else if(c=='L' && d=='X'){
                r-=10;
                r+=40;
            }
            else if(c=='C' && d!='X'){
                r+=100;
            }
            else if(c=='C' && d=='X'){
                r-=10;
                r+=90;
            }
            else if(c=='D' && d!='C'){
                r+=500;
            }
            else if(c=='D' && d=='C'){
                r-=100;
                r+=400;
            }
            else if(c=='M' && d!='C'){
                r+=1000;
            }
            else if(c=='M' && d=='C'){
                r-=100;
                r+=900;
            }
            d=c;
        }
        return r;
    }
};
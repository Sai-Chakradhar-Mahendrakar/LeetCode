class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(n>=2 && bits[n-2]==0){
            return true;
        }
        int i=0;
        while(i<n-1){
            i+=bits[i]+1;
        }
        return i==n-1;
    }
};
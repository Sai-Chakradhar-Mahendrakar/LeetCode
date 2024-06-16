class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int s=1;
        int e=*max_element(piles.begin(),piles.end());

        int res = e;

        while(s<=e){
            int k = (s+e)/2;
            long int hrs = 0;
            for(int i=0;i<n;i++){
                hrs += ceil((double)piles[i]/k);
            }

            if(hrs>h){
                s  = k+1;
            }else{
                res = min(res,k);
                e = k-1;
            }
        }

        return res;
    }
};
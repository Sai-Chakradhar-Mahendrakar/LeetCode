class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int s=1;
        int e=*max_element(piles.begin(), piles.end());
        int ans=e;

        while(s<=e){
            int mid=(s+e)/2;
            long long hrs=0;
            for(int i=0;i<n;i++){
                hrs += ceil((double)piles[i]/mid);
                if(hrs>h){
                    break;
                }
            }

            if(hrs>h){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};
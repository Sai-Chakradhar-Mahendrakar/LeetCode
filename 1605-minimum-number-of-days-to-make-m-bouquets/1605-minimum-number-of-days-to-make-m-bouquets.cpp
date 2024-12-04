class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) { 
        int s=1;
        int e=*max_element(bloomDay.begin(), bloomDay.end());
        int minDays=-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(makeBouquet(bloomDay, mid, k)>=m){
                minDays=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return minDays;
    }
private:
    int makeBouquet(auto bloomDay, auto mid, auto k){
        int bouquetCnt=0;
        int conDay=0;

        for(auto day:bloomDay){
            if(day<=mid){
                conDay++;
            }
            else{
                conDay=0;
            }

            if(conDay==k){
                bouquetCnt++;
                conDay=0;
            }
        }
        return bouquetCnt;
    }
};
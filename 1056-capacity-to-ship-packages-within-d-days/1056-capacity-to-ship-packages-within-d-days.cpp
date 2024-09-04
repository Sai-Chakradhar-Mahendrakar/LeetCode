class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(), weights.end());
        int e=sumArr(weights);
        int ans=e;

        while(s<=e){
            int mid=(s+e)/2;
            if(reqDays(weights, mid)<=days){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
private:
    int sumArr(auto& arr){
        int sum=0;
        for(auto x: arr){
            sum+=x;
        }
        return sum;
    }

    int reqDays(auto& weights, auto mid){
        int days=1;
        int wt=0;
        for(auto x:weights){
            if(wt+x>mid){
                days++;
                wt=0;
            }
            wt+=x;
        }
        return days;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n==0){
            return 0;
        }

        int maxVal=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
            maxVal = max(maxVal, arr[i]);
            if(maxVal==i){
                cnt++;
            }
        }

        return cnt;
    }
};
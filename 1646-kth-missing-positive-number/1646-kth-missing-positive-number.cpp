class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s=0;
        int e=arr.size()-1;

        while(s<=e){
            int mid=(s+e)/2;
            int noMissing=arr[mid]-(mid+1);

            if(noMissing<k){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return s+k;
    }
};
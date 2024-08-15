class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> left(n, 1);

        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        

        int right=1;
        int sum=left[n-1];
        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                right++;
            }
            else{
                right=1;
            }
            sum+=max(right, left[i]);
        }

        return sum;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        int r=n-1;
        int totalSum=0;

        for(;l<k;l++){
            totalSum+=cardPoints[l];
        }
        l--;

        int maxSum=totalSum;
        while(l>=0){
            totalSum=totalSum-cardPoints[l]+cardPoints[r];
            l--;
            r--;
            maxSum=max(maxSum, totalSum);
        }

        return maxSum;

    }
};
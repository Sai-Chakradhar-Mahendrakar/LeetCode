class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();

        if(m>n){
            return findMedianSortedArrays(b,a);
        }

        int total = m+n;
        int s=0;
        int e=m;

        double res = 0.0;

        while(s<=e){
            int i=(s+e)/2;
            int j=(total+1)/2 - i;

            int left1 = (i > 0) ? a[i - 1] : INT_MIN;
            int right1 = (i < m) ? a[i] : INT_MAX;
            int left2 = (j > 0) ? b[j - 1] : INT_MIN;
            int right2 = (j < n) ? b[j] : INT_MAX;

             if (left1 <= right2 && left2 <= right1) {
                // even
                if (total % 2 == 0) {
                    res = (max(left1, left2) + min(right1, right2)) / 2.0;
                // odd
                } else {
                    res = max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                e = i - 1;
            } else {
                s = i + 1;
            }
        }
        return res;
    }
};
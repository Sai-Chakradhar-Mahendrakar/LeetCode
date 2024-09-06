class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }

        int s=0;
        int e=m;

        double res=0.0;

        while(s<=e){
            int px = (s+e)/2; // Mid of nums1
            int py = (m+n+1)/2 - px; // nums2;

            // left half
            int x1= (px==0) ? INT_MIN: nums1[px-1];
            int x2= (py==0) ? INT_MIN: nums2[py-1];

            // Right half
            int x3= (px==m) ? INT_MAX: nums1[px];
            int x4= (py==n) ? INT_MAX: nums2[py];

            if(x1<=x4 && x2<=x3){
                //even
                if((m+n)%2==0){
                    res=max(x1, x2)+min(x3, x4);
                    res/=2.0;
                } //odd
                else{
                    res=max(x1, x2);
                }
                break;
            }
            else if(x1>x4){
                e=px-1;
            }
            else{
                s=px+1;
            }
        }
        return res;
    }
};
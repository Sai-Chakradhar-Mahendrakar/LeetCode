class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int l = 0;
        int r = n-1;
        int lar = 0;
        
        while(l<r){
           if(lmax<=rmax){
               l++;
               lmax = max(lmax,height[l]);
               lar += lmax-height[l];
           }
            else{
                r--;
                rmax = max(rmax, height[r]);
                lar += rmax-height[r];
            }
        }
        
        
        return lar;
    }
};
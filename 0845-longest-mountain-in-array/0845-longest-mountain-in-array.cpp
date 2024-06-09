class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        int lar = 0;
        for(int i=1;i<n-1;){
            if(a[i]>a[i-1] and a[i]>a[i+1]){
                int cnt=1;
                int j=i;
                while(j>=1 and a[j]>a[j-1]){
                    j--;
                    cnt++;
                }
                while(i<n-1 and a[i]>a[i+1]){
                    i++;
                    cnt++;
                }
                lar = max(lar,cnt);
            }
            else{
                i++;
            }
        }
        return lar;
    }
};
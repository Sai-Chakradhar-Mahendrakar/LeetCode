class Solution {
public:
    int search(vector<int>& a, int target) {
        int s=0;
        int e=a.size()-1;

        while(s<=e){
            int m=(s+e)/2;
            if(a[m]==target){
                return m;
            }

            if(a[s]<=a[m]){
                if(a[s]<=target and target<=a[m]){
                    e=m-1;
                }else{
                    s=m+1;
                }
            }else{
                if(a[m]<=target and target<=a[e]){
                    s=m+1;
                }else{
                    e=m-1;
                }
            }
        }
        return -1;
    }
};
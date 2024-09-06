class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n=mat.size();
        int m=mat[0].size();

        int s=0;
        int e=m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int maxRowIdx = findMaxIdx(mat, n, m, mid);
            int left = mid-1>=0 ? mat[maxRowIdx][mid-1]:-1;
            int right = mid+1<m ? mat[maxRowIdx][mid+1]:-1;
            if(mat[maxRowIdx][mid]>left && mat[maxRowIdx][mid]>right){
                return {maxRowIdx, mid};
            }
            else if(mat[maxRowIdx][mid]<left){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return {-1, -1};
    }
private:
    int findMaxIdx(auto& mat, int n, int m, int col){
        int maxVal=-1;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(maxVal<mat[i][col]){
                maxVal=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
};
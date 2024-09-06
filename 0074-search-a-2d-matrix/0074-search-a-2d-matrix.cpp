class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int s=0;
        int e=r*c-1;

        while(s<=e){
            int mid=(s+e)/2;
            // Flatten index = row * c + col
            int row=mid/c;
            int col=mid%c;

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};
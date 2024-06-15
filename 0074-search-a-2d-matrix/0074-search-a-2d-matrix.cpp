class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if (matrix.empty() || matrix[0].empty()){
        //     return false;
        // }

        // int i=0;
        // int s = 0;
        // int e = matrix[0].size()-1;
        
        // while(i<matrix.size()){
        //     while(s<=e){
        //         int mid = (s+e)/2;
        //         if(matrix[i][mid]==target){
        //             return true;
        //         }else if(matrix[i][mid]>target){
        //             e = mid-1;
        //         }else{
        //             s = mid+1;
        //         }
        //     }
        //     i++;
        //     s = 0;
        //     e = matrix[0].size()-1;
        // }
        // return false;

        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0;
        int e = n*m-1;

        while(s<=e){
            int mid=(s+e)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target){
                return true;
            }else if(matrix[r][c]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};
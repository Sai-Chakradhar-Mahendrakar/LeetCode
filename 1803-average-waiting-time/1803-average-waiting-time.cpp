class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        vector<int> cT(n,0);
        cT[0]=customers[0][0]+customers[0][1];

        for(int i=1;i<n;i++){
            if(cT[i-1]<customers[i][0]){
                cT[i]=customers[i][1]+customers[i][0];
            }
            else{
                cT[i]=cT[i-1]+customers[i][1];
            }
        }

        double sum=0;
        for(int i=0;i<n;i++){
            sum+=(cT[i]-customers[i][0]);
        }

        return sum/n;
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        vector<int> cT(n,0);
        int prev,curr;
        curr=prev=customers[0][0]+customers[0][1];
        double sum=(curr-customers[0][0]);

        for(int i=1;i<n;i++){
            if(prev<customers[i][0]){
                curr=customers[i][1]+customers[i][0];
            }
            else{
                curr=prev+customers[i][1];
            }
            prev = curr;
            sum+=(curr-customers[i][0]);
        }

        return sum/n;
    }
};
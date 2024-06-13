class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // pos time
        vector<pair<int,double>> tab;
        
        int n = speed.size();
        
        for(int i=0;i<n;i++){
            double time = (double)(target-position[i])/speed[i];
            tab.emplace_back(position[i],time);
        }
        
        sort(tab.begin(),tab.end());
        double maxTime = 0;
        int res=0;
        
        for(int i=n-1;i>=0;i--){
            double time = tab[i].second;
            if(maxTime<time){
                maxTime=time;
                res++;
            }
        }
        return res;
    }
};
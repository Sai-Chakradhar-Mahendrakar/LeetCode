class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // Index , temp
        stack<pair<int,int>> s;
        vector<int>res(n);
        
       for(int i=0;i<n;i++){
           int curDay = i;
           int curTemp = temperatures[i];
           
           while(!s.empty() and s.top().second<curTemp){
               int prevDay = s.top().first;
               int prevTemp = s.top().second;
               s.pop();
               
               res[prevDay] = curDay - prevDay;
           }
           s.push({curDay,curTemp});
       }
       return res; 
    }
};
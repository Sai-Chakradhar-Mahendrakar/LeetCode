class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        int longestBand = 0;

        for(int element: s){
            if(s.find(element-1)==s.end()){
                int next = element+1;
                int cnt=1;
                while(s.find(next)!=s.end()){
                    next++;
                    cnt++;
                }
                longestBand = max(longestBand, cnt);
            }
        }
        return longestBand;
    }
};
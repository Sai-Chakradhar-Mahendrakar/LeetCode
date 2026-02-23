class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int num: s){
            if(s.find(num-1)==s.end()){
                int next=num+1;
                int cnt=1;
                while(s.find(next)!=s.end()){
                    next++;
                    cnt++;
                }
                res=max(res, cnt);
            }
        }
        return res;
    }
};
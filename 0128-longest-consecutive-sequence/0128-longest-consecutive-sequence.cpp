class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        int lar = 0;
        
        for(auto i:nums){
            int prev = i-1;
            if(s.find(prev)==s.end()){
            int next = i+1;
            int cnt=1;
            while(s.find(next)!=s.end()){
                next++;
                cnt++;
            }
            if(cnt>lar){
                lar=cnt;
            }
            }
        }
        return lar;
    }
};
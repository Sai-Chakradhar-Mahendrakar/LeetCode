class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        int lar = 0;
        
        for(auto i:nums){
            if(s.find(i-1)==s.end()){
                int cnt=1;
                while(s.find(i+1)!=s.end()){
                    i++;
                    cnt++;
                }
                lar = max(lar,cnt);
            }
        }
        return lar;
    }
};
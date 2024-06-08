class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        
        int lar = 0;
        for(auto i:nums){
            s.insert(i);
        }
        
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
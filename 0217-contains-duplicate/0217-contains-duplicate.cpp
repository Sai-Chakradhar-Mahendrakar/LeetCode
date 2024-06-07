class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(auto x:nums){
            if(s.find(x)!=s.end()){
                return true;
            }
            else{
                s.insert(x);
            }
        }
        return false;
    }
};
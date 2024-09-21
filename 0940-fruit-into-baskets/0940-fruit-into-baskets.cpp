class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int maxFruits=0;
        int n=fruits.size();

        unordered_map<int, int> mp;
        while(r<n){
            mp[fruits[r]]++;

            if(mp.size()>2){
                if(--mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }

            maxFruits= max(maxFruits, r-l+1);
            r++;
        }
        return maxFruits;
    }
};
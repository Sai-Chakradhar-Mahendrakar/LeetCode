class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pidx=0;
        int nidx=1;
        vector<int> res(n);
        for(int num: nums){
            if(num>0){
                res[pidx]=num;
                pidx+=2;
            } else {
                res[nidx]=num;
                nidx+=2;
            }
        }
        return res;
    }
};
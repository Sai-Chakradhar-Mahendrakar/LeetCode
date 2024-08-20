class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()==0){
            return res;
        }
        int l=1;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1!=nums[i+1]){
                string str = to_string(nums[i-l+1]);
                if(l!=1){
                    str+= "->" + to_string(nums[i]);;
                }
                l=1;
                res.push_back(str);
            }
            else{
                l++;
            }
        }

        string str = to_string(nums[nums.size()-l]);
        if(l!=1){
            str+= "->" + to_string(nums[nums.size()-1]);
        }
        res.push_back(str);

        return res;
    }
};
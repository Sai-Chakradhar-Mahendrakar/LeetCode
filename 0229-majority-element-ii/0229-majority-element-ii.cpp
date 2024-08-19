class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int val1=0;
        int val2=0;

        for(int i=0;i<nums.size();i++){
            if(cnt1==0 and nums[i]!=val2){
                cnt1=1;
                val1=nums[i];
            }
            else if(cnt2==0 and nums[i]!=val1){
                cnt2=1;
                val2=nums[i];
            }
            else if(nums[i]==val1){
                cnt1++;
            }
            else if(nums[i]==val2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> res;
        int td = nums.size()/3;

        cnt1=0;
        cnt2=0;
        for(auto x:nums){
            if(val1==x){
                cnt1++;
            }
            else if(val2==x){
                cnt2++;
            }
        }

        if(cnt1>td){
            res.push_back(val1);
        }

        if(cnt2>td){
            res.push_back(val2);
        }

        return res;
    }
};
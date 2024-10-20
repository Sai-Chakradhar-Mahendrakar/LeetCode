class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        findCom(candidates, res, cur, target, 0);
        return res;
    }
private:
    void findCom(vector<int>& arr, vector<vector<int>>& res, vector<int>& cur, int target, int idx){
        if(target==0){
            res.push_back(cur);
            return;
        }

        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }

            if(arr[i]>target){
                break;
            }

            // include
            cur.push_back(arr[i]);
            // exclude
            findCom(arr, res, cur, target-arr[i], i+1);
            cur.pop_back();
        }
    }
};
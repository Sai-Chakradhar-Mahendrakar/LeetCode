class Solution {
    vector<int> temp;
public:
    int reversePairs(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin.tie(0);
        
        temp.resize(nums.size(), 0);
        return mergeSort(nums, 0, nums.size()-1);
    }

private:
    void merge(vector<int>& arr, int low, int mid, int high){
        int i = low;
        int j = mid+1;
        int k = low;

        while(i<=mid and j<=high){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }

        while(i<=mid){
            temp[k++] = arr[i++];
        }

        while(j<=high){
            temp[k++] = arr[j++];
        }

        for(int i=low;i<=high;i++){
            arr[i] = temp[i];
        }
    }

    int countPairs(vector<int> &nums, int low, int mid, int high){
        int right=mid+1;
        int cnt=0;

        for(int i=low;i<=mid;i++){
            while(right<=high and nums[i] > nums[right]*2.0){
                right++;
            }
            cnt+=(right-(mid+1));
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int cnt=0;

        if(low>=high){
            return cnt;
        }

        int mid = (low+high)/2;
        cnt+=mergeSort(nums, low, mid);
        cnt+=mergeSort(nums, mid+1, high);        
        cnt+=countPairs(nums, low, mid, high);        
        merge(nums, low, mid, high);
        
        return cnt;
    }
};
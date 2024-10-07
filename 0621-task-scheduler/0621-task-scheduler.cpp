class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        for(auto x:tasks){
            freq[x-'A']++;
        }
        
        sort(begin(freq), end(freq));
        int chunk=freq[25]-1;
        int idle=chunk*n;

        for(int i=24;i>=0;i--){
            idle-=min(chunk, freq[i]);
        }

        return idle<0?tasks.size():tasks.size()+idle;
    }
};
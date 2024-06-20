class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int f1 = pq.top();
            pq.pop();
            int f2 = pq.top();
            pq.pop();
            if(f1>f2){
                pq.push(f1-f2);
            }
        }

        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};
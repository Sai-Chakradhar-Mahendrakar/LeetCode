class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();

        vector<int> lastIdx(26);
        for(int i=0;i<n;i++){
            lastIdx[s[i]-'a']=i;
        }

        int size=0;
        int end=0;

        vector<int> result;

        for(int i=0;i<n;i++){
            size++;
            end = max(end, lastIdx[s[i]-'a']);
            if(i==end){
                result.emplace_back(size);
                size=0;
            }
        }
        return result;
    }
};
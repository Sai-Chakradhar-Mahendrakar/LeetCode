class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp(wordList.begin(), wordList.end());

        if(mp.find(endWord)==mp.end()){
            return 0;
        }

        queue<string> wq;
        wq.push(beginWord);
        int dist = 1;

        while(!wq.empty()){
            int size = wq.size();  
            for(int i=0;i<size;i++){
                string curWord = wq.front();
                wq.pop();
                
                if(curWord==endWord){
                    return dist;
                }

                for(int j=0;j<curWord.size();j++){
                    char orgChar = curWord[j];
                    for(char ch='a';ch<='z';ch++){
                        if(ch==orgChar){
                            continue;
                        }
                        curWord[j]=ch;
                        if(mp.find(curWord)!=mp.end()){
                            wq.push(curWord);
                            mp.erase(curWord);
                        }
                    }
                    curWord[j]=orgChar;
                }
            }
            dist++;
        }
        return 0;
    }
};
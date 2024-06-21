class Node{
    public:
        char data;
        unordered_map<char, Node*> m;
        bool isTerminal;
        Node(char d){
            data = d;
            isTerminal = false;
        }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                Node* n = new Node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    bool searchHelper(const string& word, int index, Node* node) {
        if(index == word.size()) {
            return node->isTerminal;
        }
        char ch = word[index];
        if(ch == '.') {
            for(auto pair : node->m) {
                if(searchHelper(word, index + 1, pair.second)) {
                    return true;
                }
            }
            return false;
        } else {
            if(node->m.count(ch) == 0) {
                return false;
            }
            return searchHelper(word, index + 1, node->m[ch]);
        }
    }


    bool search(string word) {
        Node* node = root;
        return searchHelper(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
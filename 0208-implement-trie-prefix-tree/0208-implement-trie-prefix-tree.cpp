class Node{
    public:
        char data;
        unordered_map<char, Node*>m;
        bool isTerminal;
        Node(char d){
            data = d;
            isTerminal=false;
        }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                Node* n = new Node(ch);
                temp->m[ch]=n; 
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch:prefix){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp=temp->m[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
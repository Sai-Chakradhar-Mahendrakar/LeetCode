/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> node;
        Node* h = head;

        while(h){
            node[h]=new Node(h->val);
             h = h->next;
        }

        h = head;

        while(h){
            Node* newNode = node[h];
            newNode->next = node[h->next];
            newNode->random = node[h->random];
            h = h->next;
        }
        return node[head];
    }
};
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
        unordered_map<Node*, Node*> old;
        old[nullptr] = nullptr;

        Node* current = head;
        while(current){
            Node* copy = new Node(current->val);
            old[current] = copy;
            current = current->next;
        }

        current = head;
        while(current){
            Node* copy = old[current];
            copy->next = old[current->next];
            copy->random = old[current->random];
            current = current->next;
        }

        return old[head];
        
        
    }
};

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
        // cloning the nodes and putting it after the OG node
        Node* current = head;

        while(current!=nullptr){
            Node* dummy = new Node(current->val);

            dummy->next = current->next;
            current->next = dummy;
            current = dummy->next;
        }

        // now comes the random pointers
        current = head;
        while(current != nullptr){
            if(current->random != nullptr){
                current->next->random = current->random->next;
            }
            current = current->next->next;            
        }

        // now adjust the next of the clones
        Node* dummy = new Node(0);
        Node* tail = dummy;
        current = head;
        while(current != nullptr){
            Node* copyNode = current->next;
            current->next = copyNode->next;

            tail->next = copyNode;
            tail = tail->next;

            current = current->next;
        }


        return dummy->next;
    }
};
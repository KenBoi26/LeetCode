/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = current->next;

        while(current->next){
            current->next = prev;
            prev = current;
            current = nextNode;
            nextNode = nextNode->next;
        }

        current->next = prev;

        return current;
    }
};
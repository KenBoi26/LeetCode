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
    ListNode* reverse(ListNode* &head, int k, ListNode* prev){
        ListNode* previous = prev;
        ListNode* current = head;
        ListNode* nextNode = nullptr;

        while(k--){
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        return previous;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k==1) return head;
    
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* current = head;

        

        while(true){
            ListNode* temp = current;
            int count = 0;

            while(temp && count<k){
                temp = temp->next;
                count++;
            }

            if(count < k) break;

            ListNode* nextGroup = temp;
            ListNode* newhead = reverse(current, k, nextGroup);

            prev->next = newhead;
            prev = current;
            current = nextGroup;
        }

        return dummy.next;

    }
};
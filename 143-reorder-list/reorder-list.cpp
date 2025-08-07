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
    ListNode* getLast(ListNode* current){
        while(current->next->next != nullptr){
            current= current->next;
        }
        ListNode* last = current->next;
        current->next = nullptr;
        return last;
    }

    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        bool flag = true;


        while(temp->next != nullptr){
            if(flag){
                prev = temp;
                temp = temp->next;
            }else{
                ListNode* curr = temp;
                prev->next = getLast(curr);
                prev = prev->next;
                prev->next = temp;
            }

            flag = !flag;
        }


    }
};

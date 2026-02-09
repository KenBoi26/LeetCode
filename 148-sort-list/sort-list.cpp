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
    ListNode* getMiddle(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* leftHalf, ListNode* rightHalf){
        ListNode dummy(0);
        ListNode* dummy1 = &dummy;
        while(leftHalf && rightHalf){
            if(leftHalf->val < rightHalf->val){
                dummy1->next = leftHalf;
                leftHalf = leftHalf->next;
            }else{
                dummy1->next = rightHalf;
                rightHalf = rightHalf->next;
            }

            dummy1 = dummy1->next;
        }

        if(leftHalf != nullptr) dummy1->next = leftHalf;

        if(rightHalf != nullptr) dummy1->next = rightHalf;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;

        // Disconnecting the left half and right half
        mid->next = nullptr;

        ListNode* leftHalf = sortList(left);
        ListNode* rightHalf = sortList(right);

        return merge(leftHalf, rightHalf);
    }
};
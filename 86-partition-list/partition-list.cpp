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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);

        ListNode* lp = left;
        ListNode* rp = right;

        ListNode* p1 = head;

        while(p1 != nullptr){
            if(p1->val < x){
                lp->next = p1;
                lp = lp->next;
            }else{
                rp->next = p1;
                rp = rp->next;
            }

            p1 = p1->next;
        }

        rp->next = nullptr;
        lp->next = right->next;

        return left->next;
    }
};
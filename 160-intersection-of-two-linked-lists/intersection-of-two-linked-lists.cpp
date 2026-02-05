/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int flag = 0;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        while(flag <= 2 && curr1 != curr2){
            if(curr1 == nullptr){
                curr1 = headB;
                flag++;
            }else{
                curr1 =curr1->next;
            }

            if(curr2 == nullptr){
                flag++;
                curr2 = headA;
            }else{
                curr2 = curr2->next;
            }
        }

        return curr1;
    }
};
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
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        while(curr1!=curr2 ){
            if(curr1!=nullptr){
                curr1 = curr1->next;
            }else{
                curr1 = headB;
            }

            if(curr2!=nullptr){
                curr2 = curr2->next;
            }else{
                curr2 = headA;
            }
        }

        return curr1;
        
    }
};
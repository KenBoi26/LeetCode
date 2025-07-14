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
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        ListNode* current = head;
        while(current!=nullptr){
            st.push(current->val);
            current = current->next;
        }
        int i=0, ans=0;

        while(!st.empty()){
            ans = ans + st.top()*pow(2,i);
            i++;
            st.pop();
        }

        return ans;
    }
};
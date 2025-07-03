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
struct compareList{
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compareList> pq;

        for(auto i:lists){
            if(i){
                pq.push(i);
            }
            
        }

        if(pq.empty()){
            return nullptr;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        while(!pq.empty()){
            ListNode* smallestNode = pq.top();
            pq.pop();
            current->next = smallestNode;
            current = smallestNode; 

            if(smallestNode->next != nullptr){
                pq.push(smallestNode->next);
            }
        }

        ListNode* mergedList = dummyHead->next;
        // delete dummyHead;
        return mergedList;


    }
};
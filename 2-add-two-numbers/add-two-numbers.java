/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0);
        ListNode dummy = res;
        ListNode temp1 = l1;
        ListNode temp2 = l2;
        int carry = 0;
        int sum = 0;
        while (temp1 != null || temp2 != null){
            int val1 = temp1 != null ? temp1.val : 0;
            int val2 = temp2 != null ? temp2.val : 0;
            int x = val1 + val2 + carry;
            carry = x / 10;
            sum = x % 10;
            dummy.next = new ListNode(sum);
            dummy = dummy.next;
            if (temp1 != null) temp1 = temp1.next;
            if (temp2 != null) temp2 = temp2.next;
        }
        if (carry != 0){
            dummy.next =  new ListNode(carry);
        }
        
        return res.next;
    }
}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        def getLast(current):
            while current.next.next != None:
                current = current.next
            
            last = current.next
            current.next = None
            return last
        
        if head == None or head.next == None:
            return
        
        temp = head
        prev = None
        flag = True

        while temp.next != None:
            if flag:
                prev = temp
                temp = temp.next
            else:
                curr = temp
                last = getLast(curr)
                prev.next = last
                last.next = temp
            flag = not flag
        
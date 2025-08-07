"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        old = dict()
        old[None] = None

        current = head
        while(current):
            copy = Node(current.val)
            old[current] = copy
            current = current.next
        
        current = head
        while(current):
            copy = old[current]
            copy.next = old[current.next]
            copy.random = old[current.random]
            current = current.next
        
        return old[head]
        
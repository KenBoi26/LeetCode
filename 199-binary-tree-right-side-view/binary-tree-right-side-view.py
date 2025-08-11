# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        while(not root):
            return result

        q = deque([root])
        while(len(q) > 0):
            temp = []
            length = len(q)
            for i in range(length):
                node = q.popleft()
                temp.append(node.val)

                if(node.left):
                    q.append(node.left)
                if(node.right):
                    q.append(node.right)

            result.append(temp[-1])
        
        return result
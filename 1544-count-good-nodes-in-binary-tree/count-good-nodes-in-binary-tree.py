# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, maximum):
            if not node:
                return 0
            
            result = 1 if node.val >= maximum else 0
            maximum = max(node.val, maximum)

            result += dfs(node.left, maximum)
            result += dfs(node.right, maximum)

            return result
        
        return dfs(root, root.val)
        
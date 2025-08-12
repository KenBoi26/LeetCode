# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def helper(node, minimum, maximum):
            if not node:
                return True
            
            if node.val <= minimum or node.val >= maximum:
                return False
            
            return helper(node.left, minimum, node.val) and helper(node.right, node.val, maximum)
        
        return helper(root, -float('inf'), float('inf'))
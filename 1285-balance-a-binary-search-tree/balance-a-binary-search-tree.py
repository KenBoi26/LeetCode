# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        inor = []
        def inorder(root):
            if not root:
                return
            
            inorder(root.left)
            inor.append(root.val)
            inorder(root.right)
        
        def construct(left, right):
            if left > right:
                return None
            
            mid = (left+right)//2
            node = TreeNode(inor[mid])
            node.left = construct(left,mid-1)
            node.right = construct(mid+1, right)
            return node
        
        inorder(root)
        return construct(0,len(inor)-1)
        
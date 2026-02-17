# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def subTree(nums: List[int], l: int, r: int) -> Optional[TreeNode]:
            if l>r:
                return None
            mid = (l+r)//2
            node = TreeNode(nums[mid])
            node.left = subTree(nums, l, mid-1)
            node.right = subTree(nums, mid+1, r)

            return node
        
        return subTree(nums, 0, len(nums)-1)
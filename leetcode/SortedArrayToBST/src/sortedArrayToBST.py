# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if nums: 
            root_position = len(nums) // 2
            # pass the value of the root node, left of the root, right of the root
            root = TreeNode (nums[root_position], self.sortedArrayToBST(nums[:root_position]), self.sortedArrayToBST(nums[root_position+1:]))
        else: 
            root = None
        return root
             
        
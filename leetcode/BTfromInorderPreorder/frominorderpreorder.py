# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder and not inorder:
            return None
        
        parent = TreeNode(preorder[0])
        parent_index = inorder.index(parent.val)
        parent.left = self.buildTree(preorder[1:parent_index + 1], inorder[:parent_index])
        parent.right = self.buildTree(preorder[parent_index + 1:], inorder[parent_index + 1:])
        return parent 
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # if root is in between  p and q: 
        if (p.val <= root.val <= q.val) or (q.val <= root.val <= p.val): 
            return root
        # if p and q are left of the root
        elif (root.val > p.val) and (root.val > q.val):
            return self.lowestCommonAncestor(root.left, p, q)
        # if p and q are right of the root
        elif (root.val < p.val) and (root.val < q.val):
            return self.lowestCommonAncestor(root.right, p, q)
        
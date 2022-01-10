# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
         
        # if both left and right subtrees have 0 depth, we should return 1
        # cause we have root, that means we have depth of 1
        # Since we are checking for maximum depth, we pass depths of left and 
        # right subtrees to the max() function 
        # return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
    
        stack = [[root, 1]]
        res = 0    
        while stack: 
            node, depth = stack.pop()
            
            if node: 
                res = max(res, depth)
                stack.append([node.left, depth+1])
                stack.append([node.right, depth+1])
        return res
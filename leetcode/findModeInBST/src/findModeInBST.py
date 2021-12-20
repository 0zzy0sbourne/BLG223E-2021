# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        mode = [root.val]
        freq_max = 1
        last = inf
        freq = 0 
        def inorder(node):
            nonlocal mode, freq_max, last, freq
            
            
            if node.left:
                inorder(node.left)
            if last == node.val: 
                freq += 1
                
            else: 
                if freq > freq_max: 
                    freq_max, mode = freq, [last]
                elif freq == freq_max: 
                    mode.append(last)  
                freq = 1
                last = node.val 
            if node.right: 
                inorder(node.right)
        
        inorder(root)
        if freq > freq_max: 
            return [last]
        elif freq ==freq_max: 
            mode.append(last)
        if freq_max == 1:
            return mode[1:]
        return mode
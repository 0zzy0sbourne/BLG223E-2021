class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mydict = {}
        for i, elem in enumerate(nums): 
            if elem in mydict.keys(): 
                mydict[elem] += 1
            elif elem not in mydict.keys():
                mydict[elem] = 1
            
            if mydict[elem] > 1: 
                return True
        
        return False
        
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        thisdict = {}
        res = 0 
        l = 0


        for i, elem in enumerate(s): 
            if elem not in thisdict.keys(): 
                thisdict[elem] = 1
            elif elem in thisdict.keys(): 
                thisdict[elem] += 1
            if (i-l+1) - max(thisdict.values()) > k:
                # limit exceeded 
                thisdict[s[l]] -= 1
                l+=1
            res = max(res, i-l+1)
        return res
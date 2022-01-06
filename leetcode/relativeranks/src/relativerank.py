from typing import List

def findRelativeRanks(score: List[int]) -> List[str]: 
    x = sorted(score, reverse = True) 
    l=[]

    for i in range(1, len(x) + 1): 
        if i==1:
            l.append("Gold Medal")
        elif i == 2: 
            l.append("Silver Medal")
        elif i == 3: 
            l.append("Bronze Medal")
        else: 
            l.append(str(i))
        d = dict(zip(x,l))
    return [d[i] for i in score]


score = [10,3,8,9,4]
print(findRelativeRanks(score))
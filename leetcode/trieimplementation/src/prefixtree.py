class Node: 
    def __init__(self): 
        self.children = {}
        self.endofword = False
class Trie:

    def __init__(self):
        self.root = Node()

        
    def insert(self, word: str) -> None:
        ptr = self.root
        
        for letter in word: 
            if letter not in ptr.children: 
                ptr.children[letter] = Node()
            ptr = ptr.children[letter]
        ptr.endofword = True
        
    def search(self, word: str) -> bool:
        ptr = self.root
        for letter in word: 
            if letter not in ptr.children: 
                return False # there is not path 
            ptr = ptr.children[letter]
            
        # check endofword 
        if ptr.endofword:
            return True
        else:
            return False
    
    def startsWith(self, prefix: str) -> bool:
        ptr = self.root
        for letter in prefix: 
            if letter not in ptr.children: 
                return False # there is not path 
            ptr = ptr.children[letter]
        return True           
     


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
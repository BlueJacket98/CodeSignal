# https://leetcode.com/discuss/interview-question/928723/Uber-or-OA-or-CodeSignal
# Prefix String - given two string arrays A & B, find if all strings in B 
# are prefixes of a concatenation of strings in A. 
# For example if A = {"one", "two", "three"} B = {"onetwo", "one"}, return True
# assuming all lower case words

class Trie:
    def __init__(self) -> None:
        self.children = [None for _ in range(26)]
        # self.isEnd = False

    def insert(self, word):
        node = self
        for ch in word:
            ch = ord(ch) - ord('a')
            if not node.children[ch]:
                node.children[ch] = Trie()
            node = node.children[ch]
        # node.isEnd = True

    def search(self, prefix):
        node = self
        for ch in prefix:
            ch = ord(ch) - ord('a')
            if not node.children[ch]:
                return False
            node = node.children[ch]
        return True

def isPrefixStrings(words, candidates):
    wordsConcat = words.join("")
    trie = Trie()
    trie.insert(wordsConcat)
    for candidate in candidates:
        if trie.search(candidate) == False:
            return False
    return True

print(isPrefixStrings(["one","two","four"], ["one", "onetwo"]))
print(isPrefixStrings(["one","two","four"], ["one", "onefour"]))
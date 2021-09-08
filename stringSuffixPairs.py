class Trie:
    def __init__(self) -> None:
        self.children = [None for _ in range(26)]
        self.isStart = False

    def insert(self, word: str) -> None:
        node = self
        for i in range(len(word) - 1, -1, -1):
            ch = word[i]
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                node.children[ch] = Trie()
            node = node.children[ch]
        node.isStart = True

    def search(self, word: str):
        # return isInTrie: bool, suffixWordNum: int
        node = self
        cnt = 0
        for i in range(len(word) - 1, -1, -1):
            ch = word[i]
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                return False, -1
            node = node.children[ch]
            if node.isStart == True:
                cnt += 1
        if node.isStart == True:
            # cnt excluding itself
            return True, cnt - 1
        else:
            return False, -1

class Solution:
    def stringSuffixPairs(self, words: list):
        trie = Trie()
        cnt = 0
        for word in words:
            trie.insert(word)
        for word in words:
            isInTrie, suffixWordNum = trie.search(word)
            if isInTrie:
                cnt += suffixWordNum
        return cnt

a = Solution()
print(a.stringSuffixPairs(["backdoor", "door", "back", "or"]))
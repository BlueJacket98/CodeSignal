class Trie:
    def __init__(self) -> None:
        self.children = [None for _ in range(26)]
        self.isEnd = False

    def insert(self, word: str) -> None:
        node = self
        for ch in word:
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                node.children[ch] = Trie()
            node = node.children[ch]
        node.isEnd = True

    def search(self, word: str):
        # return isInTrie: bool, prefixWordNum: int
        node = self
        cnt = 0
        for ch in word:
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                return False, -1
            node = node.children[ch]
            if node.isEnd == True:
                cnt += 1
        if node.isEnd == True:
            return True, cnt - 1
        else:
            return False, -1

class Solution:
    def stringPrefixPairs(self, words: list):
        trie = Trie()
        cnt = 0
        for word in words:
            trie.insert(word)
        for word in words:
            isInTrie, prefixWordNum = trie.search(word)
            if isInTrie:
                cnt += prefixWordNum
        return cnt

a = Solution()
print(a.stringPrefixPairs(["a", "ab", "abc", "abcde"]))
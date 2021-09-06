# LeetCode 68

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        while words != []:
            curLen = 0
            curList = []
            while curLen <= maxWidth:
                if words:
                    if curList == []:
                        curLen += len(words[0])
                        curList.append(words[0])
                        words.pop(0)
                    elif curList != [] and curLen + 1 + len(words[0]) <= maxWidth:
                        curLen += 1 + len(words[0])
                        curList.append(words[0])
                        words.pop(0)
                    elif curList != [] and curLen + 1 + len(words[0]) > maxWidth:
                        break
                else:
                    break
            
            # check if last line
            if not words:
                curStr = ""
                for i in range(len(curList)):
                    curStr += curList[i]
                    if i < len(curList) - 1:
                        curStr += " "
                curStr += " " * (maxWidth - len(curStr))
                res.append(curStr)
                continue
            # space needs to be appended
            spaceLen = maxWidth - curLen + (len(curList) - 1)
            spaceNum = len(curList) - 1
            # check if only one word
            if spaceNum == 0:
                res.append(curList[0] + " " * spaceLen)
                continue
            # normal cases
            spaceDist = [spaceLen // spaceNum for _ in range(spaceNum)]
            spaceRemainder = spaceLen % spaceNum
            for i in range(spaceRemainder):
                spaceDist[i] += 1
            # generate str
            curStr = ""
            for i in range(len(curList)):
                curStr += curList[i]
                if i <= len(spaceDist) - 1:
                    curStr += " " * spaceDist[i]
            res.append(curStr)
        return res
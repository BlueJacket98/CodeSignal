class Solution:
    def split(self, input1):
        
        lastSpace = 0
        curStart = 0
        ans = []
        totalSplit = 0
        count = 0
        i = 0
        while i < len(input1):
            count += 1
            if input1[i] == ' ':
                lastSpace = i
            if count == 155:
                if input1[i] != ' ':
                    if (i < len(input1) - 1 and input1[i+1] == ' ') or i == len(input1) - 1:
                        lastSpace = i
                totalSplit += 1
                count = 0
                ans.append(input1[curStart:lastSpace+1])
                if i > lastSpace:
                    i = lastSpace
                curStart = i + 1
            i += 1
        if curStart < len(input1):
            if totalSplit == 0:
                return [input1]
            ans.append(input1[curStart:])
            totalSplit += 1
        
        if len(ans) > 1:
            for i, s in enumerate(ans):
                ans[i] = s + '(' + str(i+1) + '/' + str(totalSplit) + ')'
        return ans

a = Solution()
print(a.split("njdksjfn jdfnds kjfdklsjf jsdofjsd f jdslkjfgdslkngdslkjg fljksdjflsfdsjfdslkfjdslkfmdsklmfgn ljsdglkdsfg d lkjgdslkgjdsljgdslkjgdsfjngds lkjsdlkgjdsgkldsjgsdlkg lkjdslkgjdslkgjdslgmnds glkjgdslkjgdslkjfgodsjfds g,mdsgkjdsngdlsknfgldsjfglkdsjfglkdsjglkdsjglkdsgjdsklgjdslk lkgjdslkgfjdslkgjdslkgjdsljfgdslkgjmdslkg kljghjdslkjgdslkjfg"))
# ['njdksjfn jdfnds kjfdklsjf jsdofjsd f jdslkjfgdslkngdslkjg fljksdjflsfdsjfdslkfjdslkfmdsklmfgn ljsdglkdsfg d lkjgdslkgjdsljgdslkjgdsfjngds (1/3)', 'lkjsdlkgjdsgkldsjgsdlkg lkjdslkgjdslkgjdslgmnds glkjgdslkjgdslkjfgodsjfds g,mdsgkjdsngdlsknfgldsjfglkdsjfglkdsjglkdsjglkdsgjdsklgjdslk (2/3)', 'lkgjdslkgfjdslkgjdslkgjdsljfgdslkgjmdslkg kljghjdslkjgdslkjfg(3/3)']['njdksjfn jdfnds kjfdklsjf jsdofjsd f jdslkjfgdslkngdslkjg fljksdjflsfdsjfdslkfjdslkfmdsklmfgn ljsdglkdsfg d lkjgdslkgjdsljgdslkjgdsfjngds (1/3)', 'lkjsdlkgjdsgkldsjgsdlkg lkjdslkgjdslkgjdslgmnds glkjgdslkjgdslkjfgodsjfds g,mdsgkjdsngdlsknfgldsjfglkdsjfglkdsjglkdsjglkdsgjdsklgjdslk (2/3)', 'lkgjdslkgfjdslkgjdslkgjdsljfgdslkgjmdslkg kljghjdslkjgdslkjfg(3/3)']
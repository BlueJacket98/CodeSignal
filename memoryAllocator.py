class MemoryAllocator:
    def __init__(self, memory) -> None:
        self.memory = memory
        self.blocks = []
        for i in range(0, len(memory), 8):
            self.blocks.append(memory[i:i+8])
        self.assignments = {}
        self.opCnt = 0

    def query(self, qry: list):
        if qry[0] == 0:
            for i in range(len(self.blocks)):
                block = self.blocks[i]
                if self.checkLeadingZeros(block, qry[1]):
                    self.opCnt += 1
                    self.assignments[self.opCnt] = [i, block]
                    block[:qry[1]] = [1 for _ in range(qry[1])]
                    return i * 8
            return -1
        elif qry[0] == 1:
            assignmentNum = qry[1]
            self.blocks[self.assignments[assignmentNum][0]] = self.assignments[assignmentNum][1]
            return self.assignments[assignmentNum][0] * 8

    def checkLeadingZeros(self, block, k):
        return block[:k] == [0 for _ in range(k)]

a = MemoryAllocator([0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0])
print(a.query([0,2]))
print(a.query([1,1]))
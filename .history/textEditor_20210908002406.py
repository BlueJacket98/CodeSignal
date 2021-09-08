from os import PathLike


class TextEditor:
    def __init__(self) -> None:
        self.content = []
        self.hist = []
        self.board = []
        
    def process(self, operations):
        for operation in operations:
            operationList = operation.split(" ")
            if operationList[0] == "INSERT":
                self.insert(operationList[1])
            elif operationList[0] == "DELETE":
                self.delete()
            elif operationList[0] == "COPY":
                self.copy(int(operationList[1]))
            elif operationList[0] == "PASTE":
                self.paste()
            elif operationList[0] == "UNDO":
                self.undo()
            print("".join(self.content))
        return "".join(self.content)
        
    def insert(self, s):
        self.content += list(s)
        self.hist.append((1, list(s)))

    def delete(self):
        deleted = self.content.pop()
        self.hist.append((-1, [deleted]))

    def copy(self, idx):
        self.board = self.content[idx:]

    def paste(self):
        self.content += self.board
        self.hist.append((1, self.board))

    def undo(self):
        lastOp = self.hist.pop()
        if lastOp[0] == "1":
            print(len(lastOp[1]))
            self.content = self.content[:-(len(lastOp[1]))]
        elif lastOp[1] == "-1":
            self.content += lastOp[1]

a = TextEditor()
print(a.process(['INSERT abcde', 'DELETE', 'COPY 2', 'PASTE', 'UNDO']))
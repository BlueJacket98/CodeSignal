def brokenKeyboard(text, letters):
    textList = text.split(" ")
    lettersSet = set(letters)
    cnt = 0
    for word in textList:
        FLAG_VALID = True
        for ch in word:
            if ch.isalpha():
                ch = ch.lower()
                if ch not in lettersSet:
                    FLAG_VALID = False
                    break
        if FLAG_VALID:
            cnt += 1
    return cnt

print(brokenKeyboard("Hello, this is CodeSignal!", ['e', 'i', 'h', 'l', 'o', 's']))
print(brokenKeyboard("Hi, this is Chris!", ['r', 's', 't', 'c', 'h']))  
print(brokenKeyboard("3 + 2 = 5", []))  
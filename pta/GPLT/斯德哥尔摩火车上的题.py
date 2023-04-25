def process(text):
    s = ""
    for i in range(1, len(text)):
        if ord(text[i]) % 2 == ord(text[i - 1]) % 2:
            s += max(text[i], text[i - 1])
    return s


t1 = process(input())
t2 = process(input())
if t1 == t2:
    print(t1, end='')
else:
    print(t1)
    print(t2, end='')

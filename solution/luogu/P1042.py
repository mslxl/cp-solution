# 莫名 WA
# 然而输出一样

record = ''
while not 'E' in record:
    record = record + input()
record = record.split('E')[0]

def jud(record,score):
    hrhr = 0
    em = 0
    for i in record:
        if i == 'W':
            hrhr = hrhr + 1
        elif i == 'L':
            em = em + 1
        if (hrhr  >= score or em >= score) and abs(hrhr - em) >= 2:
            print('%r:%r' %(hrhr,em))
            hrhr = 0
            em = 0
    print('%r:%r' %(hrhr,em))

jud(record,11)
print()
jud(record,21)
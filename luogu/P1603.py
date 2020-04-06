dict = {
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9,
    'ten': 10,
    'eleven': 11,
    'twelve': 12,
    'thirteen': 13,
    'fourteen': 14,
    'fifteen': 15,
    'sixteen': 16,
    'seventeen': 17,
    'eighteen': 18,
    'nineteen': 19,
    'twenty': 20,
    'a': 1,
    'both': 2,
    'another': 1,
    'first': 1,
    'second': 2,
    'third': 3
}

nums = []


if __name__ == "__main__":
    line = input().split(' ')
    for i in line:
        bk = False
        if i.find('.') != -1:
            i = i.split('.')[0]
            bk = True
        if i in dict.keys():
            num = dict.get(i)
            nums.append((num * num) % 100)
        if bk:
            break
    nums.sort()
    num = 0
    for i in nums:
        num = num * 100
        num = num + i
    print(num)

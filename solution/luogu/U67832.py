for i in range(5):
    print('a', end='')
    for j in range(8 - 2):
        if i == 0 or i == 4:
            print('a', end='')
        else:
            print(' ', end='')
    print('a')

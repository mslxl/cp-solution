def sudoku(puzzle):
    def vaild(puzzle):
        for m in range(9):
            if puzzle[m][j]==puzzle[i][j] and m!= i:
                return False
        for n in range(9):
            if puzzle[i][n]==puzzle[i][j] and n!= j:
                return False
        for m in range(3):
            for n in range(3):
                if puzzle[int(i/3)*3+m][int(j/3)*3+n]==puzzle[i][j] and m!= i and n!= j and int(i/3)*3+m != i and int(j/3)*3+n!=j:
                    return False
        return True
    for i in range(9):
        for j in range(9):
            if puzzle[i][j] == 0:
                for d in range(1,10):
                    puzzle[i][j] = d
                    if vaild(puzzle):
                        if sudoku(puzzle):
                            return puzzle
                        else:
                            puzzle[i][j] = 0
                    else:
                        puzzle[i][j] = 0
                return False 
    return puzzle

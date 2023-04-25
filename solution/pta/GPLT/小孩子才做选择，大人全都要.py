X, Y = [int(x) for x in input().split()]

a = max(X, Y)
b = min(X, Y)

sum = a + b

result_a = a if a > 0 else 0
result_b = sum if sum > 0 else 0

print(f"{result_a} {result_b}")
if result_b == result_a and result_a == 0:
    print("-_-")
elif result_a >= result_b:
    print("T_T")
else:
    print("^_^")

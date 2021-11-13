n = int(input())
action = []
while n != 0:
    a, b, c, d = map(int, input().split())
    action.append((a, b, c, d))
    n -= 1


def dfs(idx, attack, speed) -> int:
    if attack < 0:
        attack = 0
    if speed < 0:
        speed = 0
    if idx >= len(action):
        return attack * speed
    act = action[idx]
    use = dfs(idx+1, attack + act[0], speed - act[1])
    giveup = dfs(idx+1, attack - act[3], speed + act[2])
    return max(use, giveup)

print(dfs(0, 0, 0))

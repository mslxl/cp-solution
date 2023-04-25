ban_year, acc_year, ask1_old, ask2_old = map(int, input().split())
if ask1_old >= ban_year and ask2_old >= ban_year:
    print("{}-Y {}-Y".format(ask1_old, ask2_old))
    print("huan ying ru guan", end='')
elif ask2_old < ban_year and ask1_old < ban_year:
    print("{}-N {}-N".format(ask1_old, ask2_old))
    print("zhang da zai lai ba", end='')
elif ask1_old < ban_year and ask2_old >= acc_year:
    print("{}-Y {}-Y".format(ask1_old, ask2_old))
    print("qing 2 zhao gu hao 1", end='')
elif ask2_old < ban_year and ask1_old >= acc_year:
    print("{}-Y {}-Y".format(ask1_old, ask2_old))
    print("qing 1 zhao gu hao 2", end='')
elif ask2_old < ban_year < ask1_old < acc_year:
    print("{}-Y {}-N".format(ask1_old, ask2_old))
    print("1: huan ying ru guan", end='')
elif ask1_old < ban_year < ask2_old < acc_year:
    print("{}-N {}-Y".format(ask1_old, ask2_old))
    print("2: huan ying ru guan", end='')
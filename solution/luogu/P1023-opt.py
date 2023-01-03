import sys

st = []
ans = 0
last,next,ad,d,n,yu,bas,maxx,a,b,c = 0,0,0,0,0,0,0,0,0,0,0

tmp = 1
st.append(0)
while tmp < 100005:
    st = st + st
    tmp *= 2

if __name__ == "__main__":
    yu = int(input())
    bas,b = map(lambda x: int(x), input().split())
    st[bas] = b
    maxx = bas
    a,b = map(lambda x: int(x), input().split())
    while a != -1 or b != -1:
        st[a] = b
        if a > maxx:
            maxx = a
            a,b = map(lambda x: int(x), input().split())
    ad = int(input())
    if st[yu] == 0:
        if yu > maxx:
            st[yu] = st[maxx] - (yu - maxx) * ad
            maxx = yu
        elif yu < maxx:
            st[yu] = st[maxx] + (maxx - yu) * ad
    next = yu + 1
    last = yu - 1
    if st[last] == 0:
        st[last] = st[yu] + ad
    if st[next]==0:
        st[next] = st[yu] -ad
    x = st[yu]
    y = st[last]
    z = st[next]
    while True:
        a = (yu - bas) * x
        b = (last - bas) * y
        c = (next - bas) * z
        if b>a:
            ans -= 1
            yu -= 1
            last -= 1
            next -= 1
        elif c>a:
            ans += 1
            yu+=1
            last+= 1
            next+= 1
        elif a>=b and a >=c:
            print(ans)
            sys.exit()
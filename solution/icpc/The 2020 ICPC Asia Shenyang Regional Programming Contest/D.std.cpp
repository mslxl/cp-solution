#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, tot, lim;
char S[N];

void dfs(int x, int cnt0, int cnt1, bool st) {
    if(cnt0 > lim || cnt1 > lim) return;
    if(x == n) {
        printf("%s\n", S);
        if(++tot >= 100)
            exit(0);
        return;
    }
    S[x] = 'b';
    dfs(x+1, cnt0 + (st^1), cnt1 + st, st);
    st ^= 1;
    S[x] = 'r';
    dfs(x+1, cnt0 + (st^1), cnt1 + st, st);
}

int main() {
    scanf("%d", &n);
    long long ans = 1ll * (n + 1)/2 * ((n + 2)/2);
    lim = (n+2)/2;
    printf("%lld\n", ans);
    dfs(0, 1, 0, 0);
    return 0;
}

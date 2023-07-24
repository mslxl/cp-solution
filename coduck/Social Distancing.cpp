#include <bits/stdc++.h>
using namespace std;

using LL = long long;
int n, m;
pair<LL, LL> a[100010];

bool check(LL mid)
{
    LL t = 0, q = n;
    for (int i = 0; i < m; i ++ )
    {
        t = max(t, a[i].first);
        LL k = a[i].second - t + 1;
        if (k <= 0) continue;
        q -= (k - 1) / mid + 1;
        t = t + (k - 1) / mid * mid + mid;
    }
    return q <= 0;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i ++ ) scanf("%lld%lld", &a[i].first, &a[i].second);

    sort(a, a + m);

    LL l = 1, r = 1e18, mid;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    printf("%lld", l);

    return 0;
}

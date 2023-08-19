#include <bits/stdc++.h>
int n, k;
std::string s;
int calc(char a, char b) {
    int ans = 0;
    for (int i = 0, j = 0, t = 0; i < s.length(); ++i) {
        for (; j < s.length(); ++j) {
            if (s[j] == b) {
                if (t == k)
                break;
                else {
                    t++;
                }
            }
        }
        ans = std::max(ans, j - i);
        if (s[i] == b)t--;
    }
    return ans;
}
int main() {
    std::cin >> n >> k;
    std::cin >> s;
    int res = calc('a', 'b');
    res = std::max(res, calc('b', 'a'));
    std::cout << res << std::endl;
    return 0;
}
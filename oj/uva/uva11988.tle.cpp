#include <cstdio>
#include <cstring>
const int maxn = 100000 + 5;
int next[maxn];
char elem[maxn];
int cur;   // 指向当前光标所在节点
int last;  // 指向最后的节点
int main(int argc, char const* argv[]) {
    while (scanf("%s", elem + 1) == 1) {
        int n = strlen(elem + 1);
        cur = last = 0;
        next[0] = 0;
        // i 标志 c 所在节点
        for (int i = 1; i <= n; i++) {
            char c = elem[i];
            if (c == '[') {
                cur = 0;
            } else if (c == ']') {
                cur = last;
            } else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) {
                    last = i;
                }
                cur = i;
            }
        }
        for(int i = next[0]; i != 0; i = next[i]){
            printf("%c", elem[i]);
        }
        printf("\n");
    }

    return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>
// const int maxn = 100000 + 5;
const int maxn = 100000 + 5;
char s[maxn];
int next[maxn];
int last, cur;
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    while (scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1);
        next[0] = 0;
        last = cur = 0;
        for (int i = 1; i <= n; i++) {
            char& ch = s[i];
            if (ch == '[') {
                cur = 0;
            } else if (ch == ']') {
                cur = last;
            } else {
                // 模拟插入链表
                // 推荐画个图理解
                // 总之就是非常难懂
                next[i] = next[cur]; // 使新插入的链表节点指向当前所关注(cur)的节点所指向的节点
                // 就是让这个节点插进去，指向原来的那个节点
                // 不理解背就完了

                next[cur] = i; // 让关注(cur) 的节点指向新插入的节点
                if (cur == last) {
                    last = i;
                }
                cur = i;
            }
        }
        for(int i = next[0]; i != 0; i = next[i]){
            printf("%c", s[i]);
        }
        printf("\n");
    }


    return 0;
}
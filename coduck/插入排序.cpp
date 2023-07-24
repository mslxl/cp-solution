#include <algorithm>
#include <iostream>
using namespace std;
struct node {
  int id;
  int num;
} a[8010];
int b[8010];
int n, q;
void change(int pos) {
  while (pos > 1) {
    if (a[pos].num == a[pos - 1].num && a[pos].id > a[pos - 1].id)
      break;
    if (a[pos].num > a[pos - 1].num)
      break;
    swap(a[pos], a[pos - 1]);
    b[a[pos].id] = pos;
    pos--;
  }
  while (pos < n) {
    if (a[pos].num == a[pos + 1].num && a[pos].id < a[pos + 1].id)
      break;
    if (a[pos].num < a[pos + 1].num)
      break;
    swap(a[pos], a[pos + 1]);
    b[a[pos].id] = pos;
    pos++;
  }
}
bool cmp(node a, node b) {
  if (a.num == b.num)
    return a.id < b.id;
  else
    return a.num < b.num;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].num);
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    b[a[i].id] = i;
  }

  while (q--) {
    int op, x, v;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &v);
      a[b[x]].num = v;
      change(b[x]);
      for (int i = 1; i <= n; i++) {
        b[a[i].id] = i;
      }
    } else {
      scanf("%d", &x);
      printf("%d\n", b[x]);
    }
  }
  return 0;
}

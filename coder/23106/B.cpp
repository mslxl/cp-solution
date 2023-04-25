#include <bits/stdc++.h>

#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

const int maxn = 2 * 10e5 + 10;
int n, q;
std::string line;

int st[3][maxn][21] = {0};

/**
 * 构建倍增表
 * */
void build_ST() {
  test std::cout << "build st" << std::endl;
  for (int i = 1; i <= n; i++) {
    char &c = line[i - 1];
    if (c == 'W') {
      st[2][i][0] = st[1][i][0] = st[0][i][0] = 1;
    } else if (c == 'D') {
      st[2][i][0] = st[1][i][0] = st[0][i][0] = 0;
    } else if (c == 'L') {
      st[2][i][0] = st[1][i][0] = -1;
      st[0][i][0] = 0;
    }
  }

  for (int j = 1; j < 21; j++) {
    for (int i = 1; i <= n; i++) {
      const int left_part = i, right_part = i + (1 << (j - 1));
      for (int idx = 0; idx < 3; idx++) {
        st[idx][i][j] =
            st[idx][left_part][j - 1] +
            st[(idx + st[idx][left_part][j - 1]) % 3][right_part][j - 1];
      }
    }
  }
}

// 查询稀疏表
int ask_ST(int s, int l, int r) {
  int ans = s;
  int pos = l;
  test std::cout << "ask range [" << l << ", " << r << "], defualt value: " << s
                 << std::endl;
  while (pos < r) {
    int j = 0;
    while (pos + (1 << (j + 1)) <= r)
      j++;

    test {
      std::cout << "pos: " << pos << " -> " << (pos + (1 << j))
                << " , value+=" << st[ans % 3][pos][j] << std::endl;
    }

    ans += st[ans % 3][pos][j];
    pos += (1 << j);
  }
  ans += st[ans % 3][pos][0];
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> q;
  std::cin >> line;
  test std::cout << "Line: " << line << std::endl;

  build_ST();
  while (q--) {
    int l, r, s;
    std::cin >> l >> r >> s;
    std::cout << ask_ST(s, l, r) << std::endl;
  }

  return 0;
}

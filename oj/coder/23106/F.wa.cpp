#include <algorithm>
#include <cctype>
#include <cstdio>

template <typename T> T rd() {
  T num = 0;
  bool flag = false;
  char c;
  while ((c = getchar()) && c != '-' && !std::isdigit(c)) {
  }

  if (c == '-') {
    flag = true;
  } else {
    num += c - '0';
  }

  while ((c = getchar()) && std::isdigit(c)) {
    num *= 10;
    num += c - '0';
  }
  printf("read num %d\n", flag ? -num : num);

  return flag ? -num : num;
}

void solve() {
  int split_num = 1;

  int num, min_mid;
  num = rd<int>();
  min_mid = rd<int>();
  int arr[num + 1];
  arr[1] = rd<int>();
  int mid = arr[1];
  for (int i = 1; i <= num; i++) {
    if (i % 2 == 0) {
      mid = std::min(arr[i / 2], arr[i / 2 + 1]);
    } else {
      mid = arr[i / 2 + 1];
    }

    if (mid >= min_mid) {
      // do split
      split_num++;
      num -= i;
      i = 1;
      arr[1] = rd<int>();
      int mid = arr[1];
      printf("split at %d, now we have %d segment", mid, split_num);
    }
  }
}

int main() {
  int T;
  T = rd<int>();
  while (T--) {
    solve();
  }

  return 0;
}

#include <bits/stdc++.h>

const int maxn = 1000 + 17;
using ull = unsigned long long;

struct Big {
  char bits[maxn];
  int len;
  Big() {
    std::memset(bits, 0, sizeof(bits));
    len = 1;
  }
  Big(ull num) {
    std::memset(bits, 0, sizeof(bits));
    for (int i = 0; num != 0; i++) {
      bits[i] = num % 10;
      num /= 10;
      len = i + 1;
    }
  }

  Big(const char* str, int s, int e) {
    std::memset(bits, 0, sizeof(bits));
    len = e - s;
    for (int i = 0; i < len; i++) {
      bits[i] = (str[i + s] - '0');
    }
  }

  void print() const {
    // printf("len = %d\n", len);
    for (int i = len - 1; i >= 0; i--) {
      printf("%d", (int)bits[i]);
    }
  }

  bool operator==(const Big rhs) const {
    if (len != rhs.len) {
      return false;
    }
    for (int i = 0; i < len; i++) {
      if (bits[i] != rhs.bits[i]) {
        return false;
      }
    }
    return true;
  }

  Big operator+(const Big rhs) const {
    Big b;
    int l = std::max(rhs.len, len);
    int fin_len = l;

    for (int i = 0; i < l; i++) {
      b.bits[i] += (rhs.bits[i] + bits[i]);
      if (b.bits[i] >= 10) {
        b.bits[i + 1] += b.bits[i] / 10;
        b.bits[i] %= 10;
        fin_len = std::max(fin_len, i + 1);
      }
    }

    for (int i = l - 1; b.bits[i] >= 10; i++) {
      if (b.bits[i] >= 10) {
        b.bits[i + 1] += b.bits[i] / 10;
        b.bits[i] %= 10;
        fin_len = std::max(fin_len, i + 1);
      }
    }

    b.len = fin_len;
    printf("T:");
    this->print();
    printf("+");
    rhs.print();
    printf("=");
    b.print();
    printf("\n");

    return b;
  }

  bool operator<(const Big rhs) const {
    if (len < rhs.len) {
      return true;
    } else if (len > rhs.len) {
      return false;
    }
    for (int i = len - 1; i >= 0; i--) {
      if (bits[i] < rhs.bits[i]) {
        return true;
      } else if (bits[i] > rhs.bits[i]) {
        return false;
      }
    }
    return false;
  }
};

int n, m;
char nums[maxn];

int item_num;
int len;
int extra_item_len;

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", nums);

  item_num = m + 1;
  len = n / item_num;
  extra_item_len = n % item_num;

  if (extra_item_len == 0) {
    Big sum(nums, 0, len);
    sum.print();
    for (int i = 1; i < item_num; i++) {
      printf("+");
      Big n(nums, i * len, (i + 1) * len);
      n.print();
      sum = sum + n;
    }
    printf("=");
    sum.print();
  } else {
    item_num--;
    extra_item_len += len;

    Big min(0);
    int min_m_start_pos = -1;
    std::memset(min.bits, 9, sizeof(min.bits));

    // printf("extra_item=%d\n", extra_item_len);
    for (int i = 0; i <= item_num; i++) {
      int start_m = i * len;
      Big c(nums, start_m, start_m + extra_item_len);
      Big sum;
      for (int j = 0; j < start_m;) {
        sum = sum + Big(nums, j, j + len);
        j += len;
      }
      // printf("j=%d m=%d\n", start_m + extra_item_len, m);
      for (int j = start_m + extra_item_len; j < n;) {
        sum = sum + Big(nums, j, j + len);
        j += len;
      }

      if (sum < min) {
        min = sum;
        min_m_start_pos = i * len;
      }

      // printf("-------------\n");
    }

    min.print();
  }
  return 0;
}
#include <cmath>
#include <cstdio>

int n;
int *chess;
int num_solve = 0;
bool used[15] = {false};

bool is_valid(int endY) {
  for (int y = 0; y < endY; y++) {
    if (abs(chess[y] - chess[endY]) == endY - y) {
      return false;
    }
  }
  return true;
}

void print_answer() {
  for (int *begin = chess; begin != chess + n; begin++) {
    printf("%d ", *begin);
  }
  printf("\n");
}

void dfs(int y) {
  if (y == n) {
    num_solve++;
    if (num_solve <= 3) {
      print_answer();
    }
    return;
  }

  for (int x = 1; x <= n; x++) {
    if (!used[x]) {
      chess[y] = x;
      if (is_valid(y)) {
        used[x] = true;
        dfs(y + 1);
        used[x] = false;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  chess = new int[n];
  dfs(0);
  printf("%d", num_solve);
  return 0;
}

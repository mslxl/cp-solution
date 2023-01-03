#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = (s); (i) < e; i++)

int main() {
  std::string text;
  int trash;
  std::cin >> trash >> text;

  rep(i, 1, trash) {
      if(text[0] == text[i]){
        printf("Wrong Answer\n");
        return 0;
      }
  }

  printf("Correct\n");
  return 0;
}
#include <bits/stdc++.h>
int main() {
  int num_stu, num_bro;
  std::cin >> num_stu >> num_bro;
  int gro;
  std::cin >> gro;
  for (int i = 0; i < gro; i++) {
    int stu;
    std::cin >> stu;
    while (num_bro <= stu) {
      num_bro *= 2;
    }

    std::cout << stu << " " << (num_bro - stu) << std::endl;
    num_bro -= stu;
  }
  return 0;
}
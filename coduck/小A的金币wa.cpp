#include <bits/stdc++.h>

int n = 0;
std::string s;
std::vector<int> ps, pc, pp, lst;
int main() {
  std::cin >> n >> s;
  s = "^" + s;
  ps.resize(s.size());
  pc.resize(s.size());
  pp.resize(s.size());
  lst.resize(s.size());
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'P') {
      pc[i] = pc[i - 1];
      lst[i] = lst[i - 1];
    }else if (s[i] != 'C' && (s[i - 1] == 'C' || s[i - 1] == '^')) {
      pc[i] = pc[i - 1] + 1;
      lst[i] = i - 1;
    } else {
      pc[i] = pc[i - 1];
      lst[i] = lst[i - 1];
    }
    pp[i] = pp[i - 1] + (s[i] == 'P') * 2;
  }

#ifdef DEBUG
  for (int i = 1; i < s.size(); i++) {
    std::cerr << s[i] << " ";
  }
  std::cerr << "\n";
  for (int i = 1; i < pc.size(); i++) {
    std::cerr << pc[i] << " ";
  }
  std::cerr << "\n";
  for (int i = 1; i < lst.size(); i++) {
    std::cerr << lst[i] << " ";
  }
  std::cerr << "\n";
  for (int i = 1; i < pp.size(); i++) {
    std::cerr << pp[i] << " ";
  }
  std::cerr << "\n";
#endif

  int l = 1, r = 1;
  int bst_l, bst_r;
  int max = 0;
  while (l < s.size() && r < s.size()) {
    int cost = (pc[r] - pc[lst[l]]) + (pp[r] - pp[l - 1]);
    int value = r - l + 1;
    if (cost > n) {
      l++;
      r--;
    } else {
      if (value > max) {
        max = value;
        bst_l = l;
        bst_r = r;
      }
      r++;
    }
  }
  std::cout << max;

#ifdef DEBUG
std::cerr << bst_l << ", " << bst_r << ": " << s.substr(bst_l, bst_r - bst_l + 1) << "\n";
#endif
}




/*
10
CPCPPSSPPSS


*/
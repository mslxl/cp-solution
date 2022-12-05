#include <bits/stdc++.h>
#include <cmath>
int main() {
#define int long long
#define double long double

  int stu_num = 0;
  std::cin >> stu_num;
  std::vector<std::pair<double, bool>> stus;

  for (int i = 0; i < stu_num; i++) {
    int k;
    std::cin >> k;
    double total_credit = 0;
    double mul = 0;
    bool unaccpet = false;
    for (int j = 0; j < k; j++) {
      int credit;
      double sco;
      std::cin >> credit >> sco;
      total_credit += credit;
      mul += (credit * sco);
      if (sco < 60)
        unaccpet = true;
    }
    double com = 0;
    std::cin >> com;
    double learn = (mul / total_credit) * 0.7 + com * 0.3;
    stus.push_back(std::make_pair(learn, unaccpet));
  }
  std::sort(stus.begin(), stus.end(), std::greater<std::pair<double, bool>>());

  int coinNum = (int)(stu_num * 0.6 + 0.5);
  int fstCoinNum = (int)(stu_num * 0.2 + 0.5);

  int coin = 0;

  int idx = 0;
  int rank = 1;
  int same_rank_num = 1;
  while (coinNum > 0) {
    if (idx == 0 ) {
      if (!stus[idx].second) {
        if(fstCoinNum >= 1){
          coin+=400;
        }
        if(coinNum >= 1){
          coin+=400;
        }
      }

      idx++;
      continue;
    }
    if (idx >= stus.size()) {
      break;
    }
    if (stus[idx].first == stus[idx - 1].first) {
      same_rank_num++;
    } else {
      rank += same_rank_num;
      same_rank_num = 1;
    }
    if (!stus[idx].second) {
      if (rank <= coinNum) {
        coin += 400;
      }
      if (rank <= fstCoinNum) {
        coin += 400;
      }
    }

    idx++;
  }

  std::cout << coin;
  return 0;
}
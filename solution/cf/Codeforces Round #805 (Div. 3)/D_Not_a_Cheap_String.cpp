#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using ll = long long;
using ul = unsigned long long;

void solve() {
  ul cnt_wd[26];
  ul dec_wd[26];
  std::memset(cnt_wd, 0, sizeof(cnt_wd));
  std::memset(dec_wd, 0, sizeof(cnt_wd));
  std::string line;
  ul price, total_price = 0;
  std::cin >> line >> price;
  for (char &c : line) {
    cnt_wd[c - 'a']++;
    total_price += c - 'a' + 1;
  }

  for (int i = 25; i >= 0; i--) {
    if (total_price > price && cnt_wd[i] - dec_wd[i] != 0) {
      if (total_price - (i + 1) * cnt_wd[i] > price) {
        total_price -= (i + 1) * cnt_wd[i];
        dec_wd[i] = cnt_wd[i];
        continue;
      }
      ul del_num = cnt_wd[i] / 2;
      if (total_price - (i + 1) * del_num > price) {
        if (total_price - (i + 1) * (del_num + 1) > price) {
          total_price -= (i + 1) * cnt_wd[i];
          dec_wd[i] = cnt_wd[i];
        } else {
          total_price -= (i + 1) * (del_num + 1);
          dec_wd[i] = del_num + 1;
        }
      } else
        while (total_price - (i + 1) * del_num <= price) {
          if (total_price - (i + 1) * (del_num / 2) > price) {
            if (total_price - (i + 1) * ((del_num / 2) + 1) > price) {
              total_price -= (i + 1) * del_num;
              dec_wd[i] += del_num;
              goto end;
            }else{
              total_price -= (i + 1) * (del_num/2 + 1);
              dec_wd[i] += (del_num/2)+1;
            }
          }else if(total_price - (i + 1) * (del_num / 2) == price){
              total_price -= (i + 1) * (del_num/2);
              dec_wd[i] += (del_num/2);
              goto end;
          } else {
            del_num /= 2;
            // std::cerr << std::endl << "half to " << del_num;
          }
        }
    }
  }
end:
  for (char &ch : line) {
    if (dec_wd[ch - 'a'] != 0) {
      dec_wd[ch - 'a']--;
    } else {
      std::cout << ch;
    }
  }
  std::cout << std::endl;
}

int main() {
  ul T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  std::cout.flush();
  return 0;
}
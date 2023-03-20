#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int n;
std::set<char> male;
std::set<char> female;
std::set<char> unpaired_male;
std::map<char, std::string> male_prefer;
std::map<char, std::string> female_prefer;
std::map<char, char> f2m;
std::map<char, char> m2f;
void solve() {
  std::cin >> n;
  male.clear();
  female.clear();
  male_prefer.clear();
  female_prefer.clear();
  unpaired_male.clear();
  f2m.clear();
  m2f.clear();

  for (int i = 0; i < 2 * n; i++) {
    char ch;
    std::cin >> ch;
    if (std::islower(ch)) {
      male.insert(ch);
      unpaired_male.insert(ch);
    } else {
      female.insert(ch);
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    char gender;
    std::string list;
    std::cin >> gender;
    std::cin.get(); // trash colon
    std::getline(std::cin, list);
    // std::cerr << gender << " prefer " << list << std::endl;
    if (std::islower(gender)) {
      male_prefer[gender] = list;
    } else {
      female_prefer[gender] = list;
    }
  }
  while (!unpaired_male.empty()) {
    for (std::set<char>::iterator iter = unpaired_male.begin();
          iter != unpaired_male.end();) {
      const char m = *iter;
      for (std::string::iterator _tmp = male_prefer[m].begin();
            _tmp != male_prefer[m].end(); _tmp++) {
        char prefer_f = *_tmp;
        if (!f2m.count(prefer_f)) {
          f2m[prefer_f] = m;
          m2f[m] = prefer_f;
          iter = unpaired_male.erase(iter);
          break;
        } else if (female_prefer[prefer_f].find(m) <
          female_prefer[prefer_f].find(f2m[prefer_f])) {
          m2f.erase(f2m[prefer_f]);
          unpaired_male.insert(f2m[prefer_f]);
          f2m[prefer_f] = m;
          m2f[m] = prefer_f;
          iter = unpaired_male.erase(iter);
          break;
        }
      }
    }
  }
  for (std::set<char>::iterator i = male.begin(); i != male.end(); i++) {
    char m = *i;
    std::cout << m << " " << m2f[m] << "\n";
  }
}
int main() {
  int T;
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  while (T--) {
    solve();
    if (T != 0) {
      std::cout << "\n";
    }
  }
  return 0;
}
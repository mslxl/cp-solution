#include <array>
#include <string>

namespace ojlib {
template <std::size_t TemplateSize = 1000000> struct KMP {
  std::array<int, TemplateSize> next;

  void clear(){
    next.fill(0);
  }

  void build(const std::string &t){
    // int j =0, k = -1;
    // next[0] = -1;
    // while(j < t.size()){
    //     if(k == -1 || t[j] == t[k]){
    //         next[++j] = ++k;
    //     }else{
    //         k = next[k];
    //     }
    // }

    // Better one
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.size()) {
      if (k == -1 || t[j] == t[k]) {
        j++, k++;
        if (t[j] == t[k]) {
          next[j] = next[k];
        } else {
          next[j] = k;
        }
      } else {
        k = next[k];
      }
    }
  }

  int find(const std::string &str, const std::string &t, int pos = 0) {
    int i = pos, j = 0;
    while (i < str.size() && j < t.size()) {
      if (j == -1 || str[i] == t[j]) {
        i++, j++;
      } else {
        j = next[j];
      }
    }
    if (j >= t.size()) {
      return i - t.size() + 1;
    } else {
      return -1;
    }
  }

  int count(const std::string &s, const std::string &t) {
    int i = 0, j = 0;
    int cnt = 0;
    while (i < s.size()) {
      if (j == -1 || s[i] == t[j]) {
        i++, j++;
      } else {
        j = next[j];
      }
      if (j == t.size()) {
        // match successfully!
        // position is $i - t.size() + 1$
        cnt++;
        j = next[j];
      }
    }
    return cnt;
  }
};
} // namespace ojlib

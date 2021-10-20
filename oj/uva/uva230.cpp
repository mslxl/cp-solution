#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;
struct Book {
    std::string title;
    std::string author;
    inline bool operator<(const Book& ghs) const {
        return author < ghs.author || title < ghs.title;
    }
};

std::map<Book, int> table;
int counter = 0;
std::deque<int> shelf;

std::string ext_quote(const std::string& line) {
    auto fst = line.find('"');
    auto snd = line.find('"', fst + 1);
    return line.substr(fst + 1, snd - 1);
}

void read_books() {
    std::string line;
    while (getline(std::cin, line) && line != "END") {
        Book bk;
        bk.title = ext_quote(line);
        bk.author = line.substr(line.find("by ") + 3);
        table.insert(std::make_pair(bk, ++counter));
        shelf.push_back(counter);
    }
    std::sort(shelf.begin(), shelf.end());
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    read_books();
    std::string cmd;
    while (std::cin >> cmd && cmd != "END") {
        
    }

    return 0;
}
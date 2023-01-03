#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
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
std::map<char, std::set<std::string>> cache;
std::set<std::string> wds;
std::set<std::string> alreadyOutput;

bool beginWith(const std::string& str, const std::string& fd) {
    if (str.size() < fd.size())
        return false;
    _for(idx, 0, fd.size()) {
        if (str[idx] != fd[idx]) {
            return false;
        }
    }
    return true;
}

// bool startMatch(const std::string& suffix, const std::string& head) {
//     if (suffix.size() == 0)
//         return true;
//     std::string wd = suffix.substr(head.size());
//     auto dicts = cache[wd[0]];
//     for (auto item : dicts) {
//         if (beginWith(wd, item)) {
//             return startMatch(wd,item);
//         }
//     }
//     return false;
// }

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::string txt;
    while (std::cin >> txt) {
        if (!cache.count(txt[0])) {
            cache[txt[0]] = std::set<std::string>();
        }
        cache[txt[0]].insert(txt);
        wds.insert(txt);
    }
    for (auto wd : wds) {
        // for (auto dict : cache[wd[0]]) {
        //     if (dict.size() >= wd.size()) {
        //         continue;
        //     }
        //     if (beginWith(wd, dict)) {
        //         if (startMatch(wd, dict)) {
        //             std::cout << wd << std::endl;
        //         }
        //     }
        // }
        for (auto prefix : cache[wd[0]]) {
            if (prefix.size() >= wd.size()) {
                continue;
            }
            if (beginWith(wd, prefix)) {
                auto suffix = wd.substr(prefix.size());
                if (wds.find(suffix) != wds.end()) {
                    if (!alreadyOutput.count(wd)) {
                        alreadyOutput.insert(wd);
                        std::cout << wd << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}
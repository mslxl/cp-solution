#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using std::string;
typedef long long ll;
typedef unsigned long long ull;
struct Pos
{
    int r, c;
    Pos(int r = 0, int c = 0)
    {
        this->r = r;
        this->c = c;
    }
};
int n, m;
std::map<string, Pos> map;

std::vector<string> split_line(const string &line)
{
    std::vector<string> arr;
    int cur_pos = 0, last_pos = 0;
    while ((cur_pos = line.find(',', last_pos)) != string::npos)
    {
        arr.push_back(line.substr(last_pos, cur_pos - last_pos));
        last_pos = cur_pos + 1;
    }
    arr.push_back(line.substr(last_pos, line.size() - last_pos));
    return arr;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    std::string line;
    while (std::cin >> n >> m)
    {
        getline(std::cin, line);
        for (int r = 1; r <= n; r++)
        {
            getline(std::cin, line);
            auto arr = split_line(line);
            int c = 0;
            int last_eq_col = 0;
            for (auto item : arr)
            {
                c++;
                auto pos = Pos(r, c);
                if (!map.count(item))
                {
                    map[item] = pos;
                }
                else
                {
                    // Judge if exist (first colum)
                    auto same_content_pos = map[item];
                    if (pos.r - same_content_pos.r == 1)
                    {
                        if (last_eq_col != 0)
                        {
                            std::cout << "NO" << std::endl
                                      << same_content_pos.r << ' ' << pos.r << std::endl
                                      << c - 1 << ' ' << c << std::endl;
                            goto end_loop;
                        }
                        else
                        {
                            last_eq_col = pos.c;
                        }
                    }
                }
            }
        }
        std::cout << "YES" << std::endl;
    end_loop:
        map.clear();
    }
    return 0;
}
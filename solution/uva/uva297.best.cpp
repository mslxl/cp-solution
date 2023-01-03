#include <cstring>
#include <iostream>
#include <string>
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
const int len = 32;
int cnt = 0;
bool image[len][len];

inline int mid(int pos, int wid) {
    return pos + wid / 2;
}
void draw(int x, int y, int len) {
    char ch;
    std::cin >> ch;
    if (ch == 'p') {
        draw(mid(x, len), y, len / 2);
        draw(x, y, len / 2);
        draw(x, mid(y, len), len / 2);
        draw(mid(x, len), mid(y, len), len / 2);
    } else if (ch == 'f') {
        _for(c, x, x + len) {
            _for(r, y, y + len) {
                if (!image[c][r]) {
                    image[c][r] = true;
                    cnt++;
                }
            }
        }
    } else if (ch == 'e') {
        return;
    }
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        cnt = 0;
        memset(image, false, sizeof(image));
        draw(0, 0, len);
        draw(0, 0, len);
        std::cout << "There are " << cnt << " black pixels." << std::endl;
    }

    return 0;
}
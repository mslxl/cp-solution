#include <iostream>
#include <cstdio>

int main() {
    std::string s;
    // 系数
    double x = 0;
    double sum = 0;

    bool isLeft = true;

    char xName = 'a';

    std::cin >> s;
    unsigned long len = s.length() - 1;

    for (int i = 0; i <= len;) {
        double num = 0;
        int w = 0, tfx = 1;
        bool iX = false;
        if (s[i] == '=') {
            isLeft = false;
            i++;
        }
        if (s[i] == '+') {
            tfx = 1;
            i++;
        } else if (s[i] == '-') {
            tfx = -1;
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9') {
            num = (w * 10 * num) + (s[i] - '0');
            w++;
            ++i;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            iX = true;
            xName = s[i];
            if (num == 0) {
                num = 1;
            }
            i++;
        }
        if (!isLeft) {
            tfx = -tfx;
        }

        if (!iX) {
            sum += num * tfx;
        } else {
            x += num * tfx * -1;
        }

        if (s[i] == '*') {
            i++;
        }
    }
    double result = sum / x;
    if (result == -0) {
        result = 0;
    }
    printf("%c=%.3f", xName, result);
    return 0;
}
#include <iostream>
#include <cstring>
#include <climits>

int main()
{
    int s[20 + 20 + 40 + 1];
    std::memset(s, 0, sizeof(s));
    int s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                s[i + j + k]++;
            }
        }
    }

    int max = INT_MIN, num = INT_MIN;
    for (int i = 0; i < sizeof(s) / sizeof(int); ++i)
    {
        if (s[i] > max)
        {
            max = s[i];
            num = i;
        }
    }
    std::cout << num;
    return 0;
}
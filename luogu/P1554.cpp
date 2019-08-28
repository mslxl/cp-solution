#include <iostream>
#include <cstring>
int main()
{
    int apt[10];
    int min, max;
    std::memset(apt, 0, sizeof(apt));
    std::cin >> min >> max;
    for (auto i = min; i <= max; i++)
    {
        auto j = i;
        do
        {
            apt[j % 10]++;
        } while ((j /= 10) > 0);
    }
    std::cout << apt[0] << ' ' << apt[1] << ' ' << apt[2] << ' ' << apt[3] << ' '
              << apt[4] << ' ' << apt[5] << ' ' << apt[6] << ' ' << apt[7] << ' '
              << apt[8] << ' ' << apt[9];
    return 0;
}